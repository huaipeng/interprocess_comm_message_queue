
#include <iostream>
#include <string>
#include <fstream>
#include "boost/process.hpp"
#include "mq_manager.hpp"

using namespace std;
namespace bp = boost::process;
int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		vector<bp::child> childs;
		// three children with different ids
		vector<int> ids = {0, 1, 2};
		std::cout << "parent simulator creates " << ids.size() << " children" << std::endl;
		string child_process_name = argv[0];
		for (auto &i : ids)
		{
			MessageManager::GetInstance().CreateQueue(0, "message_queue_" + std::to_string(i));
			childs.emplace_back(bp::child(child_process_name, std::vector<std::string>{std::to_string(i)}));
		}

		int nMsg = 10;
		std::cout << "parent simulator sends " << nMsg << " to each child" << std::endl;
		for (int i = 0; i < nMsg; i++)
		{
			Message msg(i, " job " + to_string(i));
			for (auto &child : ids)
			{
				MessageManager::GetInstance().SendMessage("message_queue_" + std::to_string(child), msg);
				if (i == nMsg - 1)
				{
					//ending message
					MessageManager::GetInstance().SendMessage("message_queue_" + std::to_string(child), Message());
				}
			}
		}

		for (auto &c : childs)
		{
			c.join();
		}
		std::cout << "parent simulator exits" << std::endl;
	}
	else if (argc == 2)
	{
		int child_id = std::stoi(argv[1]);
		bool is_complete = false;
		while (!is_complete)
		{
			Message msg;
			MessageManager::GetInstance().ReadMessage("message_queue_" + std::to_string(child_id), msg);
			std::cout << "child simulator " << child_id << " picks a message {task:" << msg.type << ", content:" << msg.content << "}" << std::endl;
			if (msg.type == -1)
			{
				is_complete = true;
			}
		}
		std::cout << "child simulator " << std::to_string(child_id) << " exits" << std::endl;
	}
	return 0;
}

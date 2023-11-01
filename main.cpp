
#include <fstream>
#include <iostream>
#include <string>

#include "boost/process.hpp"
#include "mq_manager.hpp"

using namespace std;
namespace bp = boost::process;

int main(int argc, char* argv[]) {
    if (argc == 1) {
        // This is a parent process that will create child processes and send
        // tasks to them via the message queue
        vector<bp::child> childs;
        vector<int> ids = {0, 1, 2};
        std::cout << "The parent process creates " << ids.size()
                  << " child processes with different IDs." << std::endl;
        string child_process_name = argv[0];
        for (auto& i : ids) {
            MessageQueueManager::GetInstance().CreateQueue(
                0, "message_queue_" + std::to_string(i));
            childs.emplace_back(
                bp::child(child_process_name,
                          std::vector<std::string>{std::to_string(i)}));
        }

        const int nNumMsg = 10;
        std::cout << "The parent process sends " << nNumMsg
                  << " messages to each child process. " << std::endl;
        for (int i = 0; i < nNumMsg; i++) {
            // Create a message containing the assignment and send it to each
            // child
            Message msg(i, " Job " + to_string(i));
            for (auto& child : ids) {
                MessageQueueManager::GetInstance().SendMessage(
                    "message_queue_" + std::to_string(child), msg);
                if (i == nNumMsg - 1) {
                    // End communication with an empty message
                    MessageQueueManager::GetInstance().SendMessage(
                        "message_queue_" + std::to_string(child), Message());
                }
            }
        }

        for (auto& c : childs) {
            c.join();
        }
        std::cout << "Parent process exits." << std::endl;

    } else if (argc == 2) {
        // This is a child process that will receive tasks from the parent
        // process through the message queue
        int child_id = std::stoi(argv[1]);
        bool is_complete = false;
        while (!is_complete) {
            Message msg;
            MessageQueueManager::GetInstance().ReadMessage(
                "message_queue_" + std::to_string(child_id), msg);
            std::cout << "Child process " << child_id
                      << " receives a message: {Msg Id:" << msg.ID
                      << ", Msg Content:" << msg.content << "}" << std::endl;
            if (msg.ID == -1) {
                is_complete = true;
            }
        }
        std::cout << "Child process " << std::to_string(child_id) << " exits"
                  << std::endl;
    }

    return 0;
}

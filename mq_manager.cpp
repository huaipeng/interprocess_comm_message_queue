
#include "mq_manager.hpp"
#include <boost/archive/text_iarchive.hpp>
#include <iostream>
#include <sstream>

MessageManager MessageManager::instance;
MessageManager::MessageManager()
{
}

MessageManager::~MessageManager()
{
    for (auto const &x : msg_queues)
    {
        bool removal = message_queue::remove(x.first.c_str());
        if (removal)
        {
            std::cout << "remove message queue " << x.first << std::endl;
        }
    }
}

MessageManager &MessageManager::GetInstance()
{
    return instance;
}

message_queue *MessageManager::CreateQueue(int type, string name)
{
    message_queue *mq = nullptr;
    if (type == 0)
    {
        permissions perm;
        perm.set_unrestricted();
        mq = new message_queue(open_or_create, name.c_str(), MESSAGE_MAX_NUMB, MESSAGE_MAX_SIZE, perm);
        msg_queues[name] = mq;
    }
    else if (type == 1)
    {
        mq = new message_queue(open_only, name.c_str());
        msg_queues[name] = mq;
    }
    return mq;
}

message_queue *MessageManager::GetQueue(const string name)
{
    if (msg_queues.find(name) == msg_queues.end())
    {
        return nullptr;
    }
    return msg_queues[name];
}

int MessageManager::SendMessage(string name, const Message &msg)
{
    auto *mq = GetQueue(name);
    if (!mq)
    {
        mq = CreateQueue(0, name);
    }
    if (mq)
    {
        std::stringstream oss;
        boost::archive::text_oarchive oa(oss);
        oa << msg;
        std::string serialized_string(oss.str());
        mq->send(serialized_string.data(), serialized_string.size(), 0);
    }
    return 0;
}

int MessageManager::ReadMessage(string name, Message &msg)
{
    int ret = 0;
    auto *mq = GetQueue(name);
    if (!mq)
    {
        mq = CreateQueue(1, name);
    }
    if (mq)
    {
        message_queue::size_type recvd_size;
        unsigned int priority;
        std::stringstream iss;
        std::string serialized_string;
        serialized_string.resize(MESSAGE_MAX_SIZE);
        mq->receive(&serialized_string[0], MESSAGE_MAX_SIZE, recvd_size, priority);
        iss << serialized_string;
        boost::archive::text_iarchive ia(iss);
        ia >> msg;
        ret = recvd_size;
    }
    return ret;
}

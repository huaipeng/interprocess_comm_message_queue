
#ifndef message_manager_hpp
#define message_manager_hpp

#include <stdio.h>
#include <boost/serialization/string.hpp>
#include <boost/interprocess/ipc/message_queue.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <map>
#include <string>
#include "message.hpp"

using namespace boost::interprocess;
using namespace std;
#define MESSAGE_MAX_SIZE 1000
#define MESSAGE_MAX_NUMB 10000

class MessageManager
{
public:
    MessageManager();
    virtual ~MessageManager();
    /**
     * Get the instance from singleton object
     */
    static MessageManager &GetInstance();
    /**
     * create message queue
     */
    message_queue *CreateQueue(int type, string name);
    message_queue *GetQueue(const string name);
    int SendMessage(string name, const Message &msg);
    int ReadMessage(string name, Message &msg);

private:
    static MessageManager instance;
    map<string, message_queue *> msg_queues;
};

#endif /* message_manager_hpp */

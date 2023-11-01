
#ifndef message_hpp
#define message_hpp

#include <stdio.h>

#include <boost/archive/text_oarchive.hpp>
#include <boost/interprocess/ipc/message_queue.hpp>
#include <boost/serialization/string.hpp>
#include <map>
#include <string>

using namespace boost::interprocess;
using namespace std;

class Message {
   public:
    Message(int i = -1, std::string n = " Nil") : ID(i), content(n){};

    int ID;
    std::string content;

   private:
    friend class boost::serialization::access;

    template <class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& ID;
        ar& content;
    }
};

#endif /* message_hpp */

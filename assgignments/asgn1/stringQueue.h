#ifndef STRING_QUEUE_H
#define STRING_QUEUE_H

#include <string>
using namespace std;

class stringQueue 
{
    private: 
        string *list;
        int CAPACITY;
        int front, back;
    public: 
        stringQueue( );
        stringQueue(int capacity);
        bool isEmpty( );
        void enqueue(string elem);
        string dequeue( );
};

#endif

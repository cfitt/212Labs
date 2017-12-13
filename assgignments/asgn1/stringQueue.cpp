#include <iostream>
#include <string>
using namespace std;
#include "stringQueue.h"


stringQueue::stringQueue( )
{
	CAPACITY=500;
	list = new string[CAPACITY];
	front = back = -1;
}

stringQueue::stringQueue(int capacity)
{
	CAPACITY = capacity;
	list = new string[capacity];
	front = back = -1;
}

bool stringQueue::isEmpty( )
{
	return (front == back);
}

void stringQueue::enqueue(string elem)//adds an elem to the back of a queue
{
	if((CAPACITY - back) == front)
		return;
	back++;
	list[back] = elem;
}

string stringQueue::dequeue( )//returns the frst element and removes it from queue
{
	string temp;
	if(isEmpty())
		return NULL; 
	else 
	{
		front++;
		temp = list[front];
		return temp;
	}	
}

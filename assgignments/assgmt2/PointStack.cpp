//PointStack.cpp
//Colin Fitt,
#include <iostream>
#include "PointStack.h"
using namespace std;

PointStack::PointStack() : stackTop(NULL)
{
}

PointStack::~PointStack()
{
	while(stackTop!=NULL)
	{
		Node *temp = stackTop->next;
		delete stackTop;
		stackTop = temp;
	}
}

void PointStack::push(const Point & item)
{
	Node *newP = new Node(item);
	newP->next = stackTop;
	stackTop = newP;
}

Point PointStack::pop( )
{
	if(isEmpty())
		cerr<<"Empty"<<endl;
	else
	{
		Node *hold = stackTop;
		Point outPt = hold->data; 
		stackTop = stackTop->next;
		delete hold;
		return outPt;
	}
}

Point & PointStack::peek( ) const
{
//returns the data in the top node of the linked list
	if(isEmpty())
		cerr<<"Empty"<<endl;
	return(stackTop->data);
}

Point & PointStack::peekUnder( ) const
{
//returns the data in the next node from the top of the linked list
	if(isEmpty())
		cerr<<"Empty"<<endl;
	return(stackTop->next->data);
}

bool PointStack::isEmpty( ) const
{
	return (stackTop==NULL);
}

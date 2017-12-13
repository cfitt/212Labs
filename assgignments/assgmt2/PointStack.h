#ifndef POINT_STACK_H
#define POINT_STACK_H
#include "Point.h"

class Node 
{
   private:
   Point data;
   Node *next;
   
   Node(const Point & d) : data(d), next(NULL)  
   {
   }
   friend class PointStack;
};

class PointStack 
{
   private:
   Node *stackTop;

   public:
   PointStack( );
   ~PointStack( );
   void push(const Point & item);
   Point pop( );
   Point & peek( ) const;
   Point & peekUnder( ) const;
   bool isEmpty( ) const;
};

#endif

  

#include "PointStack.h"

int main ( ) 
{
   Point A(0,0);
   Point B(5,5);
   Point C(10,10);
   Point D(5,5);
   Point E(A);
   // should be false:true
   cout << boolalpha << (B==E) << ":" << boolalpha << (B==D) << endl;
   PointStack S; 
   S.push(A);
   S.push(B);
   S.push(C);
   // should be (5,5):(10,10)
   cout << S.peekUnder() << ":" << S.peek() << endl;
   // should be (10,10)(5,5)(0,0)
   while( !S.isEmpty( ) ) 
      cout << S.pop( );
   cout << endl;
}
 


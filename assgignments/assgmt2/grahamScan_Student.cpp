//grahamScan_Student.cpp
//Colin Fitt

#include <vector>
#include <cmath>
using namespace std;
#include "Point.cpp"
#include "PointStack.cpp"

double angle(Point &A, Point &B) 
{
   return atan2( B.getY()-A.getY(), B.getX() - A.getX() );
}

void sortByAngleFromFirst(vector<Point> &list)
{
   for( int round=1; round<list.size(); round++) {
      int i=round; 
      Point newPoint = list[round];
      double newAngle = angle(list[0], newPoint );
      while( i>1 && ( newAngle < angle(list[0], list[i-1]) ) ) {
	 list[i]=list[i-1];
         i--;
	}
      list[i] = newPoint;
   }
} 

void moveLeftmostFirst( vector<Point> &list ) 
{
  int leftmost=0;
   for(int i=1; i<list.size(); i++)
      if( list[i].getX() < list[leftmost].getX() ) 
          leftmost=i;
   Point temp = list[leftmost];
   list[leftmost] = list[0];
   list[0] = temp;
}

bool isLeftTurn( Point &A, Point &B, Point &C ) 
{
      return (B.getY()-A.getY())*(C.getX()-B.getX()) <
                    (C.getY()-B.getY())*(B.getX()-A.getX());
}

void debugDump( vector<Point> &list)
{
   //cout << "****";
   for(int i=0; i<list.size(); i++) 
      cout << list[i] << ",";
   cout << endl;
}

vector<Point> convexHull( vector<Point> &list)
{
	
	moveLeftmostFirst(list);
	sortByAngleFromFirst(list);
	PointStack S;
	S.push(list[0]);
	S.push(list[1]);

	int i=2; int limit=list.size();
	while (i<limit) //for(int i=2;i<limit;i++)
	{
		if(isLeftTurn(S.peekUnder(),S.peek(),list[i]))
		{
//if makes left turn w.r.t. top 2 items on stack
			S.push(list[i]);
			i++;
		}
		else 
			S.pop();
	}
//return the hull
	vector<Point> cvxhull;
	while(!S.isEmpty())
		cvxhull.push_back(S.pop());
	return cvxhull;
}

void shellIt( vector<Point> &list )//AKA ConvexLayers
{
	if(list.size() < 3)
	{
		debugDump(list);
		return;
	}

	vector<Point> hull_out = convexHull(list);
	debugDump(hull_out);

	for (int i=0; i<hull_out.size(); i++)
		for (int j=0; j<list.size(); j++)
			if (hull_out[i] == list[j])
				list.erase(list.begin()+j);
	shellIt(list);
}


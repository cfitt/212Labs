//Colin Fitt
//Point.cpp
#include "Point.h"
using namespace std;

Point::Point(int x, int y)
{
	X = x;
	Y = y;
}

Point::Point( const Point& other)
{
	X = other.X;
	Y = other.Y;
}

int Point::getX( ) const
{
	return X;
}

int Point::getY( ) const
{
	return Y;
}

bool Point::operator==(const Point & other) const
{
	return (X == other.X && Y == other.Y);
}

ostream & operator<<(ostream &out, const Point & P )
{
	out<<" ("<<P.X<<", "<<P.Y<<")";
	return out;
}

//polynomial.h
//Colin Fitt, lab 2, 212 summer

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
using namespace std;

class Polynomial
{
 public:
	Polynomial ();
	void incrementBy(int c, int p);
	bool operator==(Polynomial& p);
	friend ostream &operator<<( ostream &out, const Polynomial& p);

 private:
	int *coff;
	int *pow;
};

#endif


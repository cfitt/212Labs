//polynomial.cpp
//Colin Fitt, lab 2, 212 summer
#include <iostream>
using namespace std;
#include "polynomial.h"

Polynomial::Polynomial()
{
	coff = new int [100];
	pow = new int [100];
}

void Polynomial::incrementBy(int c, int p)
{
	if(c == 0) //cause it's 0, 
		return;
	if(p == 0) // anything to the 0 power is 1
	{
		p == 1;
		c == 1;
	}

	int i, j;

	for (i = 0; i<100 ;i++) //loop starts
	{
		if(p == pow[i]) //exits the loop because it's added onto same power, (including x^0 as 1)
		{
			coff[i] += c;
			break; 
		}
	
		else if (p > pow[i]) //If the power is larger than the one submitted
		{
			for(j = 99; j > i ;--j) //shift each one over
			{
				pow[j] = pow[j-1];
				coff[j] = coff[j-1];
			}
		pow[i] = p; //replace in spot where stopped
		coff[i] = c;
		break;
		}
	}
//rinse and repeat
}

bool Polynomial::operator==(Polynomial& other)
{
	for (int i=0; i<100;i++)
	{
		if(pow[i]!=other.pow[i] || coff[i]!=other.coff[i])
		{
			return false;
			break;
		} else {
			return true;
		}
	}	
}

ostream &operator<<( ostream &out, const Polynomial& p)
{
	bool has_varible = true;

	//print first varible first
	if (p.pow[0]==1)
		out << p.coff[0];	
	else
		out << p.coff[0] << "x^" << p.pow[0];
	

	for(int i=1;i<100;i++) //not first, then loop
	{

		if (p.pow[i]==0 && p.coff[i]==0) //empty
			break;

		if (p.pow[i]==1)
		{
			has_varible = false;
			out << " + " << p.coff[i];	
		}		
		else if (has_varible)
		{
			out << " + " << p.coff[i] << "x^" << p.pow[i];
		}
	}
	return out;
}

//test.cpp
#include<iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Recursion.h"

int main(int argc, const char *argv[])
{
	if (argc == 2)
	{
		string infile (argv[1]);  // construct object and open file
		Recursion *r = new Recursion (infile);
	}

	else if (!infile) 
	{
		cerr << "Error opening file!\n"; 
		return 1;
	}
		
}

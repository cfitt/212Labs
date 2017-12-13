#ifndef RECURSION_H
#define RECURSION_H
#include<iostream>
#include <fstream>
#include <string>
using namespace std;


class Recursion
{
	public:
	        Recursion ();
		int **copygrid(int **gridCopy);
	        void print();
	        void printGroupWith();

	private:
	        int **grid;
		int **tempGrid;
};

#endif


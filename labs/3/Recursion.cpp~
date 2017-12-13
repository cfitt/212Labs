//Recursion.cpp
#include<iostream>
#include <fstream>
#include <string>
using namespace std;

class Recursion
{
	public:
		Recursion(string name);
		int **copyGrid(int **grid);
		void print();
		bool printGroupWith(int **gridCopy, int i, int j);
	private:
		int **grid;
};

int main(int argc, const char *argv[])
{
	if (argc == 2)
	{
		string name(argv[1]);  // construct object and open file
		Recursion *r = new Recursion(name);
		r->print();
	}
}

Recursion::Recursion(string name) //a constructor or function that reads a file into the array. 
{
	grid = new int *[10];
	for (int i = 0; i < 10; i++ )
		grid[i] = new int [10];


	char c;
	ifstream infile;
	infile.open(name.c_str());
   
        cout << "This is what is what '" << name << "' looks like:" << endl;
	for (int i = 0; i < 10; i++ ) 
	{ 
		for (int j = 0; j < 10; j++ )
		{
			infile >> c;
			cout << c;
//c is the actual char being read in
//The character . should be converted to 0, and any other character converted to 1 
			if (c == '.')
				grid[i][j] = 0;
			if (c == 'X')
				grid[i][j] = 1;
		}
		cout << endl;
	}
	cout << endl;
	infile.close();
}

int** Recursion::copyGrid(int **grid) //makes a copy of grid[10][10]
{
	int **gridCopy = new int *[10];
	for (int i = 0; i < 10; i++ )
		gridCopy[i] = new int [10];
	
	for (int i = 0; i < 10; i++ ) {
		for (int j = 0; j < 10; j++ ) {
			gridCopy[i][j] = grid[i][j];
		}
	}
        return gridCopy;
}

void Recursion::print()
{
        //a function print() that causes the printout of all groups contained in the 2D array.
        //It should make a copy of the member array, and make use of a recursive method printGroupWith(). 
	int **gridCopy = copyGrid(grid);

	cout << "This Grid converted looks like is:" << endl;       
	for (int i=0;i<10;i++) //print on console to see 0s and 1s
	{
		for (int j=0;j<10;j++)
		{
			cout << gridCopy[i][j];
		}
		cout << endl;
	}
	
	cout << endl;
	int count = 1;
	cout<<"Found Groups of 1s or Xs:"<<endl;
	cout<<"Group "<<count<<":";
	for (int i=0;i<10;i++)
	{
		for (int j=0;j<10;j++)
		{
			if(printGroupWith(gridCopy, i, j))
			{
				cout<<endl;		
				count++;
				cout<<"Group "<<count<<":";	
			}		
		}
	}
}


bool Recursion::printGroupWith(int **gridCopy, int i, int j)
{
/*
//print out rows with Xs
	cout << endl << "These are the locations of the Xs or 1s:" << endl; 
	for (int i=0;i<10;i++)
	{
		cout << "Row " << i << ": ";
		for (int j=0;j<10;j++)
		{
			if (gridCopy[i][j] == 1)
			{
				cout<<"("<<i<<","<<j<<") ";
				gridCopy[i][j] = 0;
			}	
		}
	cout<<endl;
	}

*/	
	if (gridCopy[i][j] == 1)
	{
		cout<<" ("<<i<<","<<j<<") ";
		gridCopy[i][j] = 0;

		if (i!=0 && gridCopy[i-1][j] == 1)
			printGroupWith(gridCopy, i-1, j);
		if (i!=9 && gridCopy[i+1][j] == 1)
			printGroupWith(gridCopy, i+1, j);
		if (j!=0 && gridCopy[i][j-1] == 1)
			printGroupWith(gridCopy, i, j-1);
		if (j!=9 && gridCopy[i][j+1] == 1)
			printGroupWith(gridCopy, i, j+1);

		return true;
	}
	return false;
}




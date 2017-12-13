//wordLadder.cpp
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

bool laddercheck(string start, string goal, string *dicwords, int steps);
bool dic_check(string dicword, string *dicwords);

int main(int argc, const char *argv[]) 
{
        ifstream file;
	string name = "alice.txt";
	
        file.open(name.c_str());

        if (!file.is_open()) {
                cerr << "There was an error opening the input dictionary\n";
        }

	int num = 327; //number of strings in alice.txt

	int i;
	string *dicwords = new string[num];
	for(i = 0; i<num ; i++)
		file >> dicwords[i];
/*
	for(i = 0; i<num ; i++) //prints all word in dictionary
		cout<<dicwords[i]<<endl;
*/

	string start, goal;
	int steps;
       
	start = argv[1];//loads the starting word
	goal = argv[2];//loads the end word
	steps = atoi(argv[3]);

	cout<<"Checking if '" << start << "' can have a word ladder to '"<< goal << "' in " << steps << " steps" << endl;
	laddercheck(start, goal, dicwords, steps);
}

bool dic_check(string dicword, string *dicwords)
{
	for(int i = 0; i<327 ; i++)
	{
		if (dicwords[i] == dicword)
		{
			dicwords[i] = "XXXX";
			cout<<"Is a Word!: "<<dicword<<endl;
			return true;
		}
	}	
	return false;	
	
			
}

bool laddercheck(string start, string goal, string *dicwords, int steps)
{
	//change letter in start and recur
	//bunch of ifs to change each letter
	//recursion();
	char alpha[27] = "abcdefghijklmnopqrstuvwxyz";

	if (steps == 0)
	{
		return false;
	}
	//else if()

	for(int j = 0; j<4; j++)//check goal changes first
	{
		string checkgoal = start;
		checkgoal[j] = goal[j];
		//cout<<checkgoal<<endl;
		if (dic_check(checkgoal, dicwords))
		{
			cout<<"trying "<<checkgoal<<endl;
			if (checkgoal == goal)
			{
				cout<<"winner! you made it to the word!"<<endl; 
				return true;
			}
			if(laddercheck(checkgoal, goal, dicwords, (steps-1)))
				return true;
		}
	}

	for(int j = 0; j<4; j++)
	{
		for(int i = 0; i<26; i++)
		{
			string checkword = start;
			checkword[j] = alpha[i];
			//cout<<checkword<<endl;		
			if (dic_check(checkword, dicwords))
			{
				cout<<checkword<<" works"<<endl;
				if (checkword == goal)
				{
					cout<<"winner! you made it to the word!"<<endl;
					return true;
				}
				if(laddercheck(checkword, goal, dicwords, (steps-1)))
					return true;
			}
		}
	}
}


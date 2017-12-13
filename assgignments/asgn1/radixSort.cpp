#include <iostream>
using namespace std;
#include "stringQueue.h"
#include "radixSort.h"

void radixSort( string list[], int listLength )
{
	int stringlength = list[0].length();
	int count = 0;
	int n;
	stringQueue *myQueue = new stringQueue[26];
	
	for (int i = stringlength - 1; i>=0 ; i--)
	{
		for (int j = 0;j < listLength ;j++)
		{
			n = list[j].at(i) - 'a';
			myQueue[n].enqueue(list[j]); 
		}
	
		count = 0; //reset
		
		for (int i = 0;i<26;i++)
		{
			while(myQueue[i].isEmpty() == false)
			{
				list[count] = myQueue[i].dequeue();
				count++;
			}
		}
	}	
}

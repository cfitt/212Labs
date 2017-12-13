#include "WordCount.h"
#include "WordHash.h"
#include <stdlib.h> 


WordHash::WordHash(int t)
{
	size = t;
	hashtable = new WordCount* [size];
}

void WordHash::addWord(string s)
{
	
	int key;
	int len = s.length();
	int holdkey[len];
	for(int i=0; i<len; i++){
		holdkey[i]=(int)s[i];
	}
	for(int j=0; j<len; j++){
		key += holdkey[j];
	}
	key = (key * 7)%size;

	WordCount * insert;
	insert = new WordCount(s);
	if(hashtable[key] != NULL){
		hashtable[key]->incrementCount();
		//cout<<"Word already present"<<endl;
		//cout<<"Count for '"<<s<<"' is now: "<<(hashtable[key]->getCount())<<endl<<endl;
	} else {
		//cout<<"New "<<s<<" at "<<key<<endl<<endl;
		hashtable[key] = insert;
	}
}

void WordHash::printCommon()
{
	
	int freqA=0, freqB;
	int locMost;
	for(int i=1; i<(size-1); i++){
		if(hashtable[i]!=NULL){
			freqB = hashtable[i]->getCount();
			if(freqB >= freqA){
				freqA = freqB;
				locMost = i;
			}
		}
	}
	cout<<(hashtable[locMost]->getWord())<<" is the most common word"<<endl;
}



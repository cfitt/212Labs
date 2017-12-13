#include "WordCount.h"

class WordHash {
	private:
		int size;
		WordCount **hashtable;

	public:
		WordHash(int t);
		void addWord(string s);
		void printCommon();
};

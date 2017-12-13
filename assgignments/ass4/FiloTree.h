#include <vector>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Node{
	public:
		string Node_name;
		Node *left, *right, *head;
		Node(string input);
		Node(Node *A, Node *B);
		//strictly parent fuction
};

class FiloTree {
	private:
		int num;
		double **dist_grid;
		vector<Node> tree;
	public:
		int getsize();
		FiloTree(string fileName);
		double FindMin();
		~FiloTree( );
		void dump( ) const;
		static void compare( const FiloTree &A, const FiloTree &B, int size);
};




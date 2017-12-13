#include "FiloTree.h"
using namespace std;
//---------------------------------------------------------------------------
//------------------------------FiloTree Class-------------------------------
//---------------------------------------------------------------------------
FiloTree::FiloTree(string fileName)
{
	ifstream in;
	in.open(fileName.c_str());

	string temp;

//takes in first element, or the number of strings
	in >> num;
	int steps = num-1;
	string words[num];

	for(int i=0; i<num; i++)
		in>> words[i];
//create grid
	dist_grid  = new double*[num];
	for(int i=0; i<num; i++)
		dist_grid[i] = new double [num];
//fill grid with values from .txt
	for(int i=0; i<num; i++)
		for(int j=0; j<num; j++)
			in >> dist_grid[i][j];	
	cout << endl;
//---------------------------------------------------------------------------
//number of words is the number of steps taken
	for(int q=0; q<num;q++){ 
		double curr_min = FindMin();
		int row, colm;
		for(int i=0; i<num; i++)
			for(int j=0; j<num; j++)
				if(dist_grid[i][j]==curr_min){
					row=i;
					colm=j;
				}
		Node *X = new Node(words[row]);
		Node *Y = new Node(words[colm]);
		Node *header = new Node(X, Y);
		tree.push_back(*header);
		words[row] = header->Node_name;
		words[colm] = "XX--error--XX";

		for(int j=0; j<num; j++){

			dist_grid[row][j] = (dist_grid[row][j] + dist_grid[colm][j]) / 2;
			dist_grid[j][row] = dist_grid[row][j];
			dist_grid[colm][j] = 0;
			dist_grid[j][colm] = 0;				
			
			if(row==j)
				dist_grid[row][j] = 0;
		}
	}//end for
}

//-----------------------------FindMin()-------------------------------------
//simple fuction that find the max and min of a grid
//it is not required to find the max, but I thought at the
//time of creation that it would be useful

double FiloTree::FindMin()
{
	double tempMax = 0;
	
	for(int i=0; i<num; i++){
		for(int j=0; j<num; j++){
			if(dist_grid[i][j]>tempMax){
				tempMax=dist_grid[i][j];
			}
		}
	}
	for(int i=0; i<num; i++){
		for(int j=0; j<num; j++){
			if(dist_grid[i][j]<tempMax && dist_grid[i][j]!=0){
				tempMax=dist_grid[i][j];
			}
		}
	}
	return tempMax;
}

//---------------------------------------------------------------------------
FiloTree::~FiloTree( )
{
	tree.clear();
	//I love vectors
}
void FiloTree::dump( ) const
{
	int steps = num-1;
	cout<<steps<<endl;
	for(int i=0; i<(steps); i++){
		cout<<"..."<<(i+1)<<endl;
		cout<<"......"<<tree[i].left->Node_name <<endl;
		cout<<"......"<<tree[i].right->Node_name <<endl;
	}
	cout << endl;
}

void FiloTree::compare( const FiloTree &A, const FiloTree &B, int size)
{
	if (size == 0){
		cout<<endl<<"These two trees are equal"<<endl;
		return;	
	} else if(A.tree[size].left->Node_name == B.tree[size].left->Node_name &&
			A.tree[size].right->Node_name == B.tree[size].right->Node_name ){
		size--;
		compare(A,B,size);
	} else
		cout<<endl<<"These two trees are not equal"<<endl;
}

int FiloTree::getsize()
{
	//class just for geting number of strings in array
	//not needed
	return num-1;
}

//---------------------------------------------------------------------------
//------------------------------Node Class-----------------------------------
//---------------------------------------------------------------------------
//Two types of node implementation
//one is for creating the children
//other is for parent

Node::Node(string input)
{
	Node_name = input;
	left = NULL;
	right = NULL;
	head = NULL;
}

Node::Node(Node *A, Node *B)
{
	A->head = this;
	B->head = this;
	Node_name = A->Node_name + "/" + B->Node_name;
	this->left = A;
	this->right = B; 
}

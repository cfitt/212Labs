#include<iostream>
#include<string>
#include"gatewayNode.h"
using namespace std;

class GiggleTree{
	private:
		GatewayNode *head, *current;

	public:
		GiggleTree(string s);
		GatewayNode getHead();
		void giggleMeTimbers(string fruit);
		GatewayNode* branchSearch(GatewayNode *look, string fruit);
		DataNode* organize(DataNode *data, string fruit);
		void dumpItemsInOrder( ) const;
		void inOrder(GatewayNode *v) const;
		void printElement(DataNode *d) const;\
};

int main(int argc, const char *argv[])
{
	int num = argc;
	int i;
	string word;

	if(argc == 1)
	{
		cout<< "no info given"<< endl;
		return 0;
	}
	GiggleTree myTree(argv[1]);

	for(i = 2; i <num; i ++)
	{
		word = argv[i];
		myTree.giggleMeTimbers(argv[i]);
	}
	myTree.dumpItemsInOrder();
}




GiggleTree::GiggleTree(string s)
{
	head = new GatewayNode(s);
}


void GiggleTree::giggleMeTimbers(string fruit)
{
	if(head == 0){
		head = new GatewayNode(fruit);
		return;
	}
	else
		branchSearch(head, fruit);

}

GatewayNode* GiggleTree::branchSearch(GatewayNode *look, string fruit)
{
	current = new GatewayNode(fruit);

	if(!look)
	{
		look = current;
	}
	else if(current->key == look->key)
	{
		look->data = organize(look->data, fruit);
	}
	else if(current->key < look->key)
	{
		if(!look->left)
			look->left = new GatewayNode(fruit);
		look->left = branchSearch(look->left, fruit);
	}
	else if(current->key > look->key)
	{
		if(!look->right)
			look->right = new GatewayNode(fruit);
		look->right = branchSearch(look->right, fruit);
	}
	return look;
}

DataNode* GiggleTree::organize(DataNode *data, string fruit)
{
		string veg = data->element;
		int s1, s2;
		s1 = veg.length();
		s2 = fruit.length();
		DataNode *Node1 = new DataNode(fruit, NULL);

		int len;
		if(s1 < s2)
			len = s1;
		else
			len = s2;
		
		if(data == 0)
		{
			data = Node1;
			return data;
		}
		if(data->element.compare(fruit) == 0)
			return data;
		
		
		//puts nodes in alphabetical order
		for(int i = 1; i < len; i++)
		{
			if(Node1->element[i] < veg[i])
			{
				DataNode *tempN = data;
				data  = Node1;
				data->next = tempN-> next;

				if(!data->next)
					data->next = new DataNode(veg,0);
				data->next = organize(data->next, veg);
				return data;
			}
			else if(Node1->element[i] > veg[i])
			{
				if(!data->next)
					data->next = new DataNode(fruit,0);
				data->next = organize(data->next, fruit);
				return data;
			}
		}
		DataNode *tempN = data;
		data  = Node1;
		data->next = tempN-> next;
		if(!data->next){
			data->next = new DataNode(veg,0);
		}
		data->next = organize(data->next, veg);
		return data;
			
		
}

void GiggleTree::dumpItemsInOrder( ) const
{
	if( head==0 )
		cout << "Empty" << endl;
	else
	{
		inOrder(head);   	
		cout << endl; 
	}
}
void GiggleTree::inOrder(GatewayNode *v) const
{
	if( v== NULL )
		return;
	inOrder(v->left);
	printElement(v->data);
	inOrder(v->right);
}

void GiggleTree::printElement(DataNode *d) const
{
	if(d == NULL)
		return;
	cout << d->element << endl;
	printElement(d->next);
}


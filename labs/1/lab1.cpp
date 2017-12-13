#include <iostream>
using namespace std;

class NumberCount {

	public:
		NumberCount(int minA,int maxA);
		bool addElement(int num);
		bool removeElement(int num);
		void display();
		void getCount(int i);
	private:
		int max, min;
		int *A;
};

int main()
{
	NumberCount N(1,6);
	N.addElement(2);
	N.addElement(2);
	N.addElement(2);
	N.addElement(4);
	N.addElement(7);
	N.addElement(6);
	N.removeElement(1);
	N.removeElement(3);
	N.display();
}


NumberCount::NumberCount(int minA,int maxA)
{
	max = maxA;
	min = minA;
	A = new int[max+1];
}	

bool NumberCount::addElement(int num)
{
	if(num<=max && num>=min)
	{
		A[num]+=1;
		return true;
	}
	cout<<num<<" Out of range"<<endl;
	return false;
}

bool NumberCount::removeElement(int num)
{
	if (A[num]==0)
	{	
		cout<<num<<" not present"<<endl;
		return true;
	}
	if(num<=max && num>=min)
	{
		A[num]-=1;
		return true;
	}
	return false;
}

void NumberCount::display()
{
	for(int i=0; i<max+1; i++)
		if(i<=max && i>=min)
		{
			cout<< i <<": ";
			getCount(i);
			cout<<endl;
		}
}

void NumberCount::getCount(int i)
{
	if (A[i] == 0)
		return;

	for(int stars = A[i]; stars > 0; stars--)
		cout<<"*";
}

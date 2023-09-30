#include <iostream>
#include "./towers.hpp"
#include "./mystack.hpp"

using namespace std;

Towers::Towers(int num)
{
	numDisk = num;
	//allocating space for the disks in the pegs based on the num passed
	peg1 = new MyStack<int>(num);
	peg2 = new MyStack<int>(num);
	peg3 = new MyStack<int>(num);
}
//destructor
Towers::~Towers()
{	//remove the data from all pegs
	delete peg1;
	delete peg2;
	delete peg3;
}
//copy constructor
Towers::Towers(const Towers & right)
{
	numDisk = right.numDisk;
	peg1 = right.peg1;
	peg2 = right.peg2;
	peg3 = right.peg3;
}
//operator= overloading
Towers& Towers::operator=(const Towers & right)
{
	if(this == &right) // checks if they already match
	{
		return *this;
	}
	//deletes the left side
	delete peg1;
	delete peg2;
	delete peg3;
	//assigns all aspect of the right side to the left (left = right;)
	numDisk = right.numDisk;
	peg1 = right.peg1;
	peg2 = right.peg2;
	peg3 = right.peg3;
	return *this;
}
void Towers::setDisks()	//initialize start-tower by putting discs in, then print out the status of three towers after initialized
//this is the first function called to set up the disks
{
	//std::cout << numDisk << " disks to enter\n";
	for (int i = numDisk; 0 < i; i--)
	{
		//cout << i << " \n";
		peg1->push(i); // Push discs onto peg1 in descending order
	}
	//std::cout << peg1->top();
	//peg1->displayStack();
	plotPegs(); // Print the status of the three towers
	//std::cout << "done\n";
}
void Towers::move(int n, MyStack<int>* s, MyStack<int>* t, MyStack<int>* d) //move n discs from tower s to tower d by using temporary tower t
//this is the second function
{
	if (n > 0)
	{
		// Move n-1 disks from s to d while using t
		move(n - 1, s, d, t);
		//Move one from s to d
		moveOne(s, d);
		// Move n-1 disks from t to d using s
		move(n - 1, t, s, d);
	}
}
void Towers::moveOne(MyStack<int>* s, MyStack<int>* d)  //move one discs from tower s to tower d
{
	int disk = s->pop();
	//cout << "disk " << disk;
	d->push(disk); // pushes the value we popped from the initial peg to the next peg
	plotPegs();
}

void Towers::plotPegs()
{
  	if (peg1==NULL || peg2==NULL || peg3==NULL) return;

	int n1=peg1->size();
	int n2=peg2->size();
	int n3=peg3->size();
	int numDisk = n1+n2+n3;

	MyStack<int> tmp1(*peg1);
	MyStack<int> tmp2(*peg2);
	MyStack<int> tmp3(*peg3);

	//plot
	for (int i=0; i<numDisk; i++) {
		//peg1
		if (numDisk-n1-i>0) {
			for (int j=0; j<numDisk; j++)
				cout << " ";
		}
		else {
			int m1 = tmp1.top();
			tmp1.pop();
			for (int j=0; j<m1; j++)
				cout << "*";
			for (int j=m1; j<numDisk; j++)
				cout << " ";
		}
		cout <<" | ";

		//peg2
		if (numDisk-n2-i>0) {
			for (int j=0; j<numDisk; j++)
				cout << " ";
		}
		else {
			int m2 = tmp2.top();
			tmp2.pop();
			for (int j=0; j<m2; j++)
				cout << "*";
			for (int j=m2; j<numDisk; j++)
				cout << " ";
		}
		cout <<" | ";

		//peg3
		if (numDisk-n3-i>0) {
			for (int j=0; j<numDisk; j++)
				cout << " ";
		}
		else {
			int m3 = tmp3.top();
			tmp3.pop();
			for (int j=0; j<m3; j++)
				cout << "*";
			for (int j=m3; j<numDisk; j++)
				cout << " ";
		}
		cout<<endl;
	}
	cout << "_________________________________________\n";
}
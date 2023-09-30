#ifndef TOWERS_HPP
#define TOWERS_HPP

#include "./mystack.hpp"

class Towers {
	private:
		MyStack<int> *peg1; //start stack
		MyStack<int> *peg2; //tmp stack
		MyStack<int> *peg3; //destination stack
		int numDisk;	//number of discs to move
	public:
		Towers(int);
		
		~Towers();
		
		Towers(const Towers &);

	   Towers& operator=(const Towers &);
	   
		void start() {
			setDisks();
			move(numDisk, peg1, peg2, peg3); 
		}
		
	private:
		void setDisks();	//initialize start-tower by putting discs in, then print out the status of three towers after initialized
		void plotPegs();	//print out the status of three towers
		void move(int n, MyStack<int>* s, MyStack<int>* t, MyStack<int>* d); //move n discs from tower s to tower d by using a temporary tower t
		void moveOne(MyStack<int>* s, MyStack<int>* d);  //move one discs from tower s to tower d
};
#endif

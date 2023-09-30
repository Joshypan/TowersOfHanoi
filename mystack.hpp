#ifndef MYSTACK_HPP
#define MYSTACK_HPP


#include <iostream>
using namespace std;

template <class T>
class MyStack
{
private:
   T *stackArray;  // Pointer to the stack array
   int stackSize;    // The stack size
   int numElem;		//index of the top element in the stack array

public:
   MyStack(int);	//pass in an int: tells the maximum size of the stack

   MyStack(const MyStack &);

   MyStack& operator=(const MyStack &);

   ~MyStack();

   // Stack operations
   void push(T);	//add an item to the stack by passing in a value
   T pop();	//pop a value out by returning the value
   T top();	//return the value at the top position in the stack
   bool isFull() const;	//tell if the stack is full
   bool isEmpty() const;	//tell if the stack is empty
   int size() const;	//tell how many items are in the stack
};

template <class T>
MyStack<T>::MyStack(int num)
{
	stackArray = new T [num]; // allocating memory the size of num for the stack array
	stackSize = num;
	numElem = -1; // top element
	//std::cout << "adding\n" << num;
}
template <class T>
MyStack<T>::MyStack(const MyStack<T> & obj)
{
	if (obj.stackSize > 0)
		stackArray = new T[obj.stackSize];
	else
		stackArray = nullptr;
	// Copy the stackSize attribute.
	stackSize = obj.stackSize;

	for (int count = 0; count < stackSize; count++)
	{
		stackArray[count] = obj.stackArray[count];
	}
	numElem = obj.numElem;
}
template <class T>
MyStack<T>& MyStack<T>::operator=(const MyStack<T> & obj)
{
	if(this == &obj)
	{
		return *this;
	}
	if (obj.stackSize > 0)
		stackArray = new int[obj.stackSize];
	else
		stackArray = nullptr;
	// Copy the stackSize attribute.
	stackSize = obj.stackSize;
	// Copy the stack contents.
	for (int count = 0; count < stackSize; count++)
	stackArray[count] = obj.stackArray[count];
	// Set the top of the stack.
	numElem = obj.numElem;
	
	return *this;
}
template <class T>
MyStack<T>::~MyStack()
{
	delete[] stackArray;
}

template <class T>
void MyStack<T>::push(T num)
{
	if (isFull())
    {
        std::cout << "The stack is full.\n";
    }
    else
    {
        numElem++;
        stackArray[numElem] = num;
    }
}
template <class T>
T MyStack<T>::pop()
{
	int num = 0;
    if (isEmpty())
    {
        std::cout << "The stack is empty.\n";
    }
    else
    {
        num = stackArray[numElem];
        numElem--;
    }
    return num;
}
template <class T>
T MyStack<T>::top()
{
	return stackArray[numElem];
}
template <class T>
bool MyStack<T>::isFull() const
{
	bool status;
	if (numElem == stackSize - 1)
	{
		status = true;
	}
	else
	{
		status = false;
	}
	return status;
}
template <class T>
bool MyStack<T>::isEmpty() const
{
	bool status;
	if (numElem == -1)
		status = true;
	else
		status = false;
	return status;
}
template <class T>
int MyStack<T>::size() const
{
	return numElem + 1;
}
/*template <class T>
void MyStack<T>::displayStack()
{
    if (isEmpty())
    {
        std::cout << "The stack is empty.\n";
    }
    else
    {
        std::cout << "Stack #:\n";
        for (int i = numElem - 1; i >= 0; i--)
        {
            std::cout << stackArray[i]->value << std::endl;
        }
    }
}*/
#endif


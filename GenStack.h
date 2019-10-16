/*
Sarah Monthofer
2317035
monthofer@chapman.edu
CPSC 350 - Assignment 3
*/

#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>

using namespace std;

template <class X>
class GenStack
{
  // https://www.techiedelight.com/stack-implementation-using-templates/ - used to make a template class
  X *myArray;
  X *myTempArray;
  int top;
  int max;

  public:
    GenStack(); // default constuctor
    GenStack(int maxsize); // overload constuctor
    ~GenStack(); // destructor

    void push(X);
    X pop();
    X peek();

    bool isEmpty();
    bool isFull();
    int size();
    void resize();
};

// Default Constructor
template <class X>
GenStack<X>::GenStack()
{
  myArray = new X[128];
  size = 128;
  top = -1;
  myTempArray = new X[size];
}

// Overload Constructor - initialize stack
template <class X>
GenStack<X>::GenStack(int maxsize)
{
  // int max;
  myArray = new X[maxsize];
  max = maxsize;
  top = -1;
  myTempArray = new X[max];
}

// Destructor to destory the stack data when the program is done
template <class X>
GenStack<X>::~GenStack() {
  delete []myArray;
  delete []myTempArray;
  exit(1);
}

// push - insert an element at the top of the array
template <class X>
void GenStack<X>::push(X x)
{
  if (isFull() == 1)
  {
    cout << "ERROR - Stack Is Full" << endl;
    resize();
    push(x);
  }
  else {
    myArray[++top] = x;
  }
}

// pop - remove the top element of the array
template <class X>
X GenStack<X>::pop()
{
  if (isEmpty() == 1)
  {
    cout << "ERROR - Stack Is Empty" << endl;
    exit(1);
  }
  else
  {
    return myArray[top--];
  }
}

// peek - look at the top element of the array without removing it
template <class X>
X GenStack<X>::peek()
{
  if (top != -1)
  {
    return myArray[top];
  }
  else
  {
    cout << "ERROR - Stack Is Currently Empty" << endl;
  }
}

// size - return the amount of elements in the arrays
template <class X>
int GenStack<X>::size()
{
  return top + 1;
}

// resize - create a new larger stack when the current stack is full
template <class X>
void GenStack<X>::resize()
{
  int size;
  // create a temporary array
  myTempArray = new X[max];

  // copy current data into the temporary array
  for (int i = 0; i < top; ++i) {
    myTempArray[i] = myArray[i];
  }

  // create a new array twice the size of the previous array
  int newSize = max * 2;
  size = newSize;
  myArray = new X[size];

  // transfer the data held in the temporary array into the new, larger array
  for (int i = 0; i < top; ++i) {
    myArray[i] = myTempArray[i];
  }
}

// isEmpty - return true or flase if the stack is empty
template <class X>
bool GenStack<X>::isEmpty()
{
  return (top == -1);
}

// isFull - return true or false if the stack is full
template <class X>
bool GenStack<X>::isFull()
{
  return top == max - 1;
}

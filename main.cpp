/*
Sarah Monthofer
2317035
monthofer@chapman.edu
CPSC 350 - Assignment 3
*/

#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include "GenStack.h"
#include "Delimiters.h"

using namespace std;

int main(int argc, char** argv) {
  Delimiters curr;

  if (argc != 2)
  {
    cout << "ERROR - INVALID NUMBER OR ARGUMENTS" << endl;
    exit(1);
  }

  std::ifstream myFile(argv[1]);

  if (!myFile)
  {
    cout << "ERROR - THE FILE YOU INPUTED CANNOT BE OPENED" << endl;
    exit(1);
  }

  if (myFile.peek() == std::ifstream::traits_type::eof())
  {
    cout << "ERROR - THE FILE YOU INPUTED IS EMPTY" << endl;
    exit(1);
  }

  else
  {
    cout << "File succesfully opened" << endl;
    cout << endl;
    curr.findDelimiters(myFile);
  }
  return 0;
}

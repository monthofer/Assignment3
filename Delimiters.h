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

using namespace std;

class Delimiters {
  private:

  public:
    Delimiters();
    ~Delimiters();

    int findDelimiters(ifstream &myFile);
};

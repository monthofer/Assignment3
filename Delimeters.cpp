/*
Sarah Monthofer
2317035
monthofer@chapman.edu
CPSC 350 - Assignment 3
*/

#include <iostream>
#include <fstream>
#include <string>
#include "GenStack.h"
#include "Delimiters.h"

using namespace std;

//Constructor
Delimiters::Delimiters() {

}

// Destructor
Delimiters::~Delimiters() {

}

 // file reading
 // http://math.hws.edu/eck/cs225/s03/files_and_strings.html

int Delimiters::findDelimiters(ifstream &myFile) {
  GenStack<char> stack(20);
  string line;
  int curLine = 0;
  // read from input file, line by line
  while (std::getline(myFile, line)) {
    ++curLine;
    for (int i = 0; i < line.length(); i++) {
      // http://www.cplusplus.com/forum/beginner/24492/
      char ch = line[i];
      // we only care about the delimeters in a file
      if (ch == '{' || ch == '}' || ch == '[' || ch == ']' || ch == '(' || ch == ')') {

        // if the user inputs a closing delimeter but the stack is empty then it is missing its pair
        if ((ch == '}' || ch == ']' || ch == ')') && stack.isEmpty()) {
          cout << "ERROR - on line " << curLine << " - Stack is Empty " << endl;
          exit(1);
        }
        // if current character is an opening delimeter add it to the stack
        else if (ch == '{' || ch == '[' || ch == '(') {
          stack.push(ch);
        }
        // deals with closing delimeters
        // if the current character is equal to the top item on the stack then remove it from stack
        else if (stack.peek() == '{' && ch == '}') {
          stack.pop();
        }

        else if (stack.peek() == '[' && ch == ']') {
          stack.pop();
        }

        else if (stack.peek() == '(' && ch == ')') {
          stack.pop();
        }

        // if we reached this point there has to be an error
        else {
          cout << "Error on line " << curLine << endl;
          cout << endl;

          if (stack.peek() == '{') {
            cout << "Missing }" << endl;
          }

          else if (stack.peek() == '[') {
            cout << "Missing ]" << endl;
          }

          else {
            cout << "Missing )" << endl;
          }
        }
      }
    }
  }

  // start at beggening of the file for the next use
  myFile.clear(); // reset file beggening pointer
  myFile.seekg(0, std::ios::beg); // start from beggening of file

  return 0;
}
// https://www.quora.com/How-does-one-read-input-until-the-end-of-file-end-of-line-in-C++


//
// bool goAgain = true;
// string userInput;
//
// while (goAgain) {
//   cout << "File Checking Complete - No Errors Found" << endl;
//   cout << endl;
//
//   cout << "Would you like to Check Another File? (Y/N)" << endl;
//   cin >> userInput;
//
//   if (userInput == 'Y' || userInput == 'y' || userInput == "yes" || userInput == "Yes") {
//     cout << "Enter Filename: " << endl;
//     cin >> myFile;
//     goAgain = true;
//   }
//
//   else {
//     cout << endl;
//     cout << "Exiting Program " << endl;
//     goAgain = false;
//     exit(1);
//   }
// }

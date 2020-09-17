#include <iostream>
#include <fstream>
#include <istream>
#include <string.h>
#include <sstream>
#include <string>
using namespace std;

bool checkInteger(string input) { //pointers work like index. it will traverse through whole string input and if pointer reaches a noninteger number, it will no longer run.
    char *p;
    int lineCount = strtol(input.c_str(), &p, 10);
    if (lineCount < 0) { //
      return false;
     } // int > 0 check
    return (*p == 0);
}

void wordProcessingFunc(int line, int indent, istream& input) {
  string userString;    // Input
  string whitespace = "";
  for (int i = 0; i < indent; i++) {
    whitespace += " ";
  }

  string output;      // 8 whitespaces
  int characterCount = whitespace.length(); //8
  bool newPara = true;
  bool first = true;
  bool firstWord = true;

  while (getline(input, userString)) {
    istringstream s(userString); //gets rid of whitespaces
    string word;
    // checks if stringstream blank/only whitespaces
    // if true, its a new paragraph
    if (s.rdbuf()->in_avail() == 0) { //points to end of line (points to next char if its = 0 then its a new paragraph
      newPara = true;
      characterCount = whitespace.length();
      continue;
    }

    while (s >> word) {
      if (newPara && !first) { //first serves as safeguard to avoid entrance into block of first paragraph
        cout << output << endl << endl;
        output = whitespace;
        firstWord = true; // indicator that the next word is the new firstword                    //"        Hamilton"
                                                //"is a musical"
      }                                         //"..."
      if (first) { //
        output = whitespace;
        first = false;
      }
      if (firstWord) {
        if (characterCount + word.length() > line) {
          output += word;
          cout << output << endl;
          firstWord = true;
          output = ""; // output is empty because we emptied output in cout << output << endl;
          characterCount = 0;
          newPara = false; // false due to entering into new paragraph
          continue;
        }
        firstWord = false;
      }


      // Check if current output + " " + word exceeds line length
      if (characterCount + 1 + word.length() > line) {
        cout << output << endl;
        characterCount = word.length();
        output = word; //
      } else {
          if (characterCount == 0 || newPara) {
            output += word;
            newPara = false;
            characterCount += word.length();      //8 11 16 26 32
          } else {                                //-LL=30,
            output += " " + word;
            characterCount += word.length() + 1;
          }
      }
    }
  }
  cout << output << endl;
  return;
}



int main (int argc, char *argv[])  {
    int lineLength = 40;
    int indentLength = 8; // commented because IDE treated unused variables as errors
    int fileCount = 0;
    ifstream infile;
    for (int i = 1; i < argc; i++) {
      	string command = argv[i]; //either IN or LL
      	char dashcheck = command.at(0); //
      	if (dashcheck == '-') { // its standard input
        // -LL=(integer)
        	string commandCheck = command.substr(0,3); //-JO
        	if (commandCheck != "-LL" && commandCheck != "-IN") {
          		cout << "UNRECOGNIZED FLAG " << argv[i] << endl;
            	return 1;
        	}
            else {
          		if (command[3] != '=') {
            		cout << "MISSING = SIGN " << argv[i] << endl;
              		return 1;
                }
                else {
            		string number = command.substr(4, command.size()); //traverses after = sign and to end of input
            		if(checkInteger(number)) {
              		// its a proper flag therefore update value
              			if (commandCheck == "-LL") {
                			lineLength = stoi(number);
                        }
                    	else {
                			indentLength = stoi(number);
                        }
                    }
                    else { //integer isnt >0
              			cout << "VALUE NOT INTEGER > 0 "<< argv[i] << endl;
                		return 1;
            		}
          		}
            }
        }
        else {
            if (fileCount == 0 ) {
            	infile.open(argv[i]);
            	if (infile.is_open() == false) {
                	cout << "UNABLE TO OPEN FILE " << argv[1] << endl;
                	return 1;
            	}
            	else if (infile.is_open() == true) {
                	fileCount++;
                    //istream in;
                }
            }
            else {
                cout << "TOO MANY FILENAMES" << endl;
                fileCount++;
                return 1;
            }
        }
    }
    if (fileCount == 1) {
      wordProcessingFunc(lineLength, indentLength, infile); //line = lineLength, indentLength = indent, infile = &cin;
    }
    else if (fileCount == 0) {
      wordProcessingFunc(lineLength, indentLength, cin);
    }

    return 0;
}

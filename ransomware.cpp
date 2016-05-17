/*
Authors: Kelly Morales, Brittney Ryn
Date: 4/12/2016
Description: This program asks the user for a text file, immediately encrypts
it, then prompts the user with quiz questions. If the quiz questions are
answered correctly, the file is decrypted, otherwise it is lost forever.
Exiting the program means the file will be encrypted forever as well.
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void encrypt(string filename);
void decrypt(string filename);
int findIdxInEncrypted(char c);
bool quiz();

char normal[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char encrypted[] = {'t', 'h', 'e', 'q', 'u', 'i', 'c', 'k', 'b', 'r', 'o', 'w', 'n', 'f', 'x', 'j', 'u', 'm', 'p', 'd', 'v', 'l', 'a', 'z', 'y', 'g'};

int main() {
  cout << "Welcome to file proofreader!" << endl << "Once you choose a file, we will proofread it and return a copy to you with our" << endl << "corrections." << endl;
  cout << "Please choose a file to proofread: ";
  string filename;
  cin >> filename;
  encrypt(filename);
  cout << "GOTCHA! Your file has been encrypted. Your file will be lost forever unless you answer the following questions correctly!" << endl;
  bool complete = false;
  while(complete == false){
    complete = quiz();
  }
  decrypt(filename);
  cout << "Fine, I guess you can have your file back. " << endl;
  return 0;
}

void encrypt(string filename) {
  ifstream input;
  input.open(filename.c_str());
  ofstream output;
  output.open("GOTCHA.txt");
  char c;
  while (input.get(c)) {
    tolower(c);
    output << encrypted[c-97];
  }
  input.close();
  output << endl;
  output.close();
  ofstream other;
  other.open(filename);
  other << "GOTCHA!" << endl;
  other.close();
}

void decrypt(string filename) {
  ifstream input;
  input.open("GOTCHA.txt");
  ofstream output;
  output.open(filename.c_str());
  char c;
  while (input.get(c)) {
    int idx = findIdxInEncrypted(c);
    cout << normal[idx] << endl;
    output << normal[idx];
  }
  input.close();
  output << endl;
  output.close();
}

int findIdxInEncrypted(char c) {
  for (int i = 0; i < 26; i++) {
    if (c == encrypted[i]) {
      return i;
    }
  }
}

bool quiz (){
  cout << endl;
  cout << "What color is the sky? " << endl << endl;
  cout << "A) Blue" << endl;
  cout << "B) Green" << endl;
  cout << "C) Red" << endl;
  cout << "D) Purple" << endl;
  char answer;
  cin >> answer;
    if (answer == 'a' || answer == 'A')
      {
	cout << "Correct" << endl;
      }
    else
      cout << "Incorrect" << endl;
    cout << endl;
    //    answer = '';
    cout << "What color is grass? " << endl;
    cout << "A) Blue" << endl;
    cout << "B) Green" << endl;
    cout << "C) Red" << endl;
    cout << "D) Purple" << endl;
    cin >> answer;
    if (answer == 'b' || answer == 'B')
	{
	  cout << "Correct" << endl;
	}
    else
      cout << "Incorrect" << endl;
  cout << endl;
  
  return true;
}



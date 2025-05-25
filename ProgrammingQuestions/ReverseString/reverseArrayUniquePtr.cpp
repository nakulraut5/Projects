// Online C++ compiler to run C++ program online
#include <iostream>
#include <memory>
using namespace std;

int main() {
  unique_ptr < char[] > mainStr = make_unique < char[] > (6);
  for (int i = 0; i < 5; i++) {
    mainStr[i] = 'A' + i;
  }
  mainStr[5] = '\0';
  cout << "Main Str: " << mainStr.get() << endl;
  unique_ptr < char[] > revStr = make_unique < char[] > (6);
  int j = 0;
  for (int i = 4; i >= 0; i--) {
    revStr[j] = mainStr[i];
    j++;
  }
  revStr[5] = '\0';
  cout << "Reverse Str: " << revStr.get() << endl;
  // delete[] mainStr;// no need
  // delete[] revStr; // no need
  return 0;
}
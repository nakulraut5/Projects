#include <iostream>
using namespace std;
int main(){
    char* mainStr = new char[5];
    for(int i=0;i<5;i++){
        mainStr[i]='A'+i;
    }
    cout << "Main Str: "<< mainStr << endl;
    char* revStr = new char[5];
    int j=0;
    for(int i=4;i>=0;i--){
        revStr[j]=mainStr[i];
        j++;
    }
    cout << "Reverse Str: "<< revStr << endl;
    delete[] mainStr;
    delete[] revStr;
    return 0;
}
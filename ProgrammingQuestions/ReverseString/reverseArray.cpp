#include <iostream>
using namespace std;
int main(){
    char* mainStr = new char[6];
    for(int i=0;i<5;i++){
        mainStr[i]='A'+i;
    }
    mainStr[5]='\0';
    cout << "Main Str: "<< mainStr << endl;
    char* revStr = new char[6];
    int j=0;
    for(int i=4;i>=0;i--){
        revStr[j]=mainStr[i];
        j++;
    }
    revStr[5]='\0';
    cout << "Reverse Str: "<< revStr << endl;
    delete[] mainStr;
    delete[] revStr;
    return 0;
}
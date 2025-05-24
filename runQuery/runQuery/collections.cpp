
#include "header.h"
#include <iostream>
namespace utils{
	int report_error(int x){
		if(x!=ITK_ok){
			std::cout << "error: x" << std::endl;
		}
		return x;
	}
	void cleanUpStrings(char** cValues, int count) {
		for (int i = 0; i < count; i++) {
			delete[] cValues[i];  // Safe cleanup of individual strings
		}
	}
}
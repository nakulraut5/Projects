#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool checkRepeat(char c, char ref[], int size) {
    for (int i = 0; i < size; i++) {
        if (ref[i] == c) {
            return true;  // If character exists, return true
        }
    }
    return false;
}

int main() {
    const char *refStr = "Monnnon";
    int len = strlen(refStr);
    char cDuplChar[len];  // Duplicate character storage
    int iDupCharCntr = 0;

    // Find duplicate characters
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (refStr[j] == refStr[i]) {
                if (!checkRepeat(refStr[i], cDuplChar, iDupCharCntr)) {
                    cDuplChar[iDupCharCntr++] = refStr[i];  // Store duplicate
                }
                break;
            }
        }
    }

    // Null-terminate the duplicate array to prevent garbage output
    cDuplChar[iDupCharCntr] = '\0';

    // Print duplicate characters
    printf("Duplicate characters: %s\n", cDuplChar);
    
    return 0;
}
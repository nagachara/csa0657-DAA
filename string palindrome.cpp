#include <stdio.h>
#include <string.h>
#include <ctype.h>


int isPalindrome(char str[]) {
    int l = 0;
    int h = strlen(str) - 1;
    for (int i = 0; i <= h; i++) {
        str[i] = tolower(str[i]);
    }

  
    while (h > l) {			
        if (!isalnum(str[l])) {
            l++;
        } else if (!isalnum(str[h])) {
            h--;
        } else if (str[l] != str[h]) {
            return 0; 
        } else {
            l++;
            h--;
        }
    }
    return 1; 
}

int main() {
    char str[100];
    printf("Enter a string: ");
    gets(str);
    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}

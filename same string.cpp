#include <stdio.h>
#include <string.h>

int main() {
    char source[100], destination[100];

   
    printf("Enter the source string: ");
    gets(source);

 
    strcpy(destination, source);

    
    printf("The destination string is: %s\n", destination);

    return 0;
}

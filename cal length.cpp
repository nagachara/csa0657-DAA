#include <stdio.h>
#include <string.h>
int calculateLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}
int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    int lengthUsingStrlen = strlen(str);
    int lengthUsingManualMethod = calculateLength(str);
    printf("Length of the string using strlen: %d\n", lengthUsingStrlen);
    printf("Length of the string using manual method: %d\n", lengthUsingManualMethod);
    return 0;
}

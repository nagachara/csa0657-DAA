#include <stdio.h>
int sumOfDigits(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;  
        n = n / 10;     
    }
    return sum;
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int result = sumOfDigits(num);
    printf("Sum of the digits of %d is %d\n", num, result);
    return 0;
}

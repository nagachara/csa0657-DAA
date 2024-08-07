#include <stdio.h>

int main() {
    int n, factors = 0;
    
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            factors += i;
        }
    }
    
    if (n == factors) {
        printf("It's a perfect number\n");
    } else {
        printf("It's not a perfect number\n");
    }
    
    return 0;
}

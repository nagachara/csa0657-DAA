#include <stdio.h>

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int a1 = 0, a2 = 1, a3;
    int a[50];
    for (int i = 0; i < 10; i++) {
        a[i] = a1;
        printf("%d ", a[i]);
        a3 = a1 + a2;
        a1 = a2;
        a2 = a3;
    }

    int sum = 0;
    for (int i = 0; i <= n * 2; i += 2) {
        sum += a[i];
    }
    
    printf("\nSum: %d\n", sum);

    return 0;
}

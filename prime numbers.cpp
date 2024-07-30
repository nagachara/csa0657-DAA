#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void sieveOfEratosthenes(int n) {
    bool *prime = (bool *)malloc((n + 1) * sizeof(bool));
    for (int i = 0; i <= n; i++) {
        prime[i] = true;
    }
    prime[0] = prime[1] = false;

    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            printf("%d ", p);
        }
    }
    printf("\n");
    free(prime);
}
int main() {
    int n;
    printf("Enter the upper limit to generate prime numbers: ");
    scanf("%d", &n);
    printf("Prime numbers up to %d are: \n", n);
    sieveOfEratosthenes(n);
    return 0;
}

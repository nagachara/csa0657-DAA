#include <stdio.h>
int binomialCoeff(int n, int k) {
    int C[n + 1][k + 1];
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= k; j++) {
            C[i][j] = 0;
        }
    }
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= i && j <= k; j++) {
            // Base cases
            if (j == 0 || j == i) {
                C[i][j] = 1;
            } else {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }

    return C[n][k];
}
int main() {
    int n = 5;
    int k = 2;
    printf("Binomial Coefficient C(%d, %d) is %d\n", n, k, binomialCoeff(n, k));
    return 0;
}

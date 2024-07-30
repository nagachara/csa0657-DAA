#include <stdio.h>
#include <stdbool.h>

#define MAX 100 

void printSubset(int subset[], int subsetSize) {
    for (int i = 0; i < subsetSize; i++) {
        printf("%d ", subset[i]);
    }
    printf("\n");
}

void subsetSum(int set[], int subset[], int n, int subsetSize, int total, int nodeIndex, int targetSum) {
    if (total == targetSum) {
        printSubset(subset, subsetSize);
        return;
    }

    if (nodeIndex == n || total > targetSum) {
        return;
    }
    subset[subsetSize] = set[nodeIndex];
    subsetSum(set, subset, n, subsetSize + 1, total + set[nodeIndex], nodeIndex + 1, targetSum);
    subsetSum(set, subset, n, subsetSize, total, nodeIndex + 1, targetSum);
}

int main() {
    int set[MAX], n, targetSum;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);
    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    int subset[MAX];

    printf("Subsets with sum %d are:\n", targetSum);
    subsetSum(set, subset, n, 0, 0, 0, targetSum);

    return 0;
}

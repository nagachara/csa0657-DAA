#include <stdio.h>
#include <limits.h>
void findMinMax(int arr[], int n) {
    int min = INT_MAX;
    int max = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Minimum value in the list: %d\n", min);
    printf("Maximum value in the list: %d\n", max);
}
int main() {
    int n;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    findMinMax(arr, n);
    return 0;
}

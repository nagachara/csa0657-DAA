#include <stdio.h>
#include <limits.h>

#define MAX 20

// Function to find the minimum cost
int findMinCost(int cost[MAX][MAX], int n, int worker, int mask, int dp[MAX][1 << MAX], int path[MAX][1 << MAX]) {
    if (worker == n) {
        return 0;
    }

    if (dp[worker][mask] != -1) {
        return dp[worker][mask];
    }

    int minCost = INT_MAX;
    int bestJob = -1;

    for (int job = 0; job < n; job++) {
        if (!(mask & (1 << job))) {
            int currentCost = cost[worker][job] + findMinCost(cost, n, worker + 1, mask | (1 << job), dp, path);

            if (currentCost < minCost) {
                minCost = currentCost;
                bestJob = job;
            }
        }
    }

    path[worker][mask] = bestJob;
    return dp[worker][mask] = minCost;
}

// Function to print the assignment of jobs to workers
void printAssignment(int path[MAX][1 << MAX], int n) {
    int mask = 0;

    printf("Optimal Assignment of Jobs:\n");
    for (int worker = 0; worker < n; worker++) {
        int job = path[worker][mask];
        printf("Worker %d -> Job %d\n", worker, job);
        mask |= (1 << job);
    }
}

int main() {
    int cost[MAX][MAX];
    int dp[MAX][1 << MAX];
    int path[MAX][1 << MAX];
    int n;

    printf("Enter the number of workers/jobs: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            dp[i][j] = -1;
            path[i][j] = -1;
        }
    }

    int minCost = findMinCost(cost, n, 0, 0, dp, path);

    printf("Minimum Cost: %d\n", minCost);
    printAssignment(path, n);

    return 0;
}

#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

int knapsackGreedy(int weights[], int values[], int n, int W) {
    int totalValue = 0;
    for (int i = 0; i < n; i++) {
        if (weights[i] <= W) {
            totalValue += values[i];
            W -= weights[i];
        }
    }
    return totalValue;
}

int knapsackDP(int weights[], int values[], int n, int W) {
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]],
                               dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}

int main() {
    int weights[] = {2, 3, 4, 5};
    int values[] = {3, 4, 5, 6};
    int W = 5;
    int n = sizeof(weights) / sizeof(weights[0]);

    printf("Greedy Knapsack Value: %d\n", knapsackGreedy(weights, values, n, W));
    printf("DP Knapsack Value: %d\n", knapsackDP(weights, values, n, W));
    return 0;
}

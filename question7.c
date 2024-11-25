#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsackBacktrack(int weights[], int values[], int n, int W, int idx, int currentWeight, int currentValue, int *maxValue) {
    if (currentWeight > W) return;

    if (idx == n) {
        *maxValue = max(*maxValue, currentValue);
        return;
    }

    knapsackBacktrack(weights, values, n, W, idx + 1, currentWeight, currentValue, maxValue);
    knapsackBacktrack(weights, values, n, W, idx + 1, currentWeight + weights[idx], currentValue + values[idx], maxValue);
}

int main() {
    int weights[] = {2, 3, 4, 5};
    int values[] = {3, 4, 5, 6};
    int W = 5;
    int n = sizeof(weights) / sizeof(weights[0]);
    int maxValue = 0;

    knapsackBacktrack(weights, values, n, W, 0, 0, 0, &maxValue);

    printf("Max Value (Backtracking): %d\n", maxValue);
    return 0;
}

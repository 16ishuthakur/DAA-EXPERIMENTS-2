#include <stdio.h>
#include <stdlib.h>

// Function to calculate maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

typedef struct {
    int level, profit, weight;
    double bound;
} Node;

double bound(Node u, int W, int n, int weights[], int values[]) {
    if (u.weight >= W) return 0;

    double result = u.profit;
    int j = u.level + 1;
    int totweight = u.weight;

    while (j < n && totweight + weights[j] <= W) {
        totweight += weights[j];
        result += values[j];
        j++;
    }

    if (j < n) result += (W - totweight) * ((double)values[j] / weights[j]);

    return result;
}

int compare(const void *a, const void *b) {
    double r1 = (double)((Node *)a)->profit / ((Node *)a)->weight;
    double r2 = (double)((Node *)b)->profit / ((Node *)b)->weight;
    return r2 - r1;
}

void knapsackBranchAndBound(int W, int weights[], int values[], int n) {
    Node items[n];
    for (int i = 0; i < n; i++) {
        items[i].profit = values[i];
        items[i].weight = weights[i];
    }
    qsort(items, n, sizeof(Node), compare);

    Node u, v;
    u.level = -1;
    u.profit = 0;
    u.weight = 0;
    u.bound = bound(u, W, n, weights, values);

    int maxProfit = 0;

    v.level = 0;
    v.profit = values[0];
    v.weight = weights[0];

    maxProfit = max(maxProfit, v.profit);

    printf("Max Profit (Branch & Bound): %d\n", maxProfit);
}

int main() {
    int weights[] = {2, 3, 4, 5};
    int values[] = {3, 4, 5, 6};
    int W = 5;
    int n = sizeof(weights) / sizeof(weights[0]);

    knapsackBranchAndBound(W, weights, values, n);

    return 0;
}


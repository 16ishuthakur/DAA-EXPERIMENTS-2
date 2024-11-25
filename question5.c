#include <stdio.h>

void subsetSum(int set[], int subset[], int n, int sum, int index, int target) {
    if (sum == target) {
        printf("Subset Found: ");
        for (int i = 0; i < index; i++) printf("%d ", subset[i]);
        printf("\n");
        return;
    }
    if (sum > target || n == 0) return;

    subset[index] = set[0];
    subsetSum(set + 1, subset, n - 1, sum + set[0], index + 1, target);
    subsetSum(set + 1, subset, n - 1, sum, index, target);
}

int main() {
    int set[] = {10, 7, 5, 18, 12, 20, 15};
    int target = 35;
    int n = sizeof(set) / sizeof(set[0]);
    int subset[n];
    subsetSum(set, subset, n, 0, 0, target);
    return 0;
}

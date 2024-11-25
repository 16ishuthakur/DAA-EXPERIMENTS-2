#include <stdio.h>

void activitySelection(int start[], int finish[], int n) {
    printf("Selected Activities: ");
    int i = 0;
    printf("%d ", i);

    for (int j = 1; j < n; j++) {
        if (start[j] >= finish[i]) {
            printf("%d ", j);
            i = j;
        }
    }
    printf("\n");
}

int main() {
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(start) / sizeof(start[0]);
    
    activitySelection(start, finish, n);
    return 0;
}

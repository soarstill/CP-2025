#include <stdio.h>
#include <stdlib.h>

int compare_ints(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);  // 오름차순
}

int main() {
    int arr[] = {5, 3, 7, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, n, sizeof(int), compare_ints);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}

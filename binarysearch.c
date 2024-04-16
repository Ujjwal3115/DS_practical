#include <stdio.h>

int binarySearch(int arr[], int n, int x) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid; 
        else if (arr[mid] < x)
            low = mid + 1; 
        else
            high = mid - 1; 
    }

    return -1; 
}

int main() {
    int arr[] = {3, 5, 7, 9, 11, 13, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 9; 

    int result = binarySearch(arr, n, x);

    if (result != -1)
        printf("Element %d found at index %d\n", x, result);
    else
        printf("Element %d not found\n", x);

    return 0;
}

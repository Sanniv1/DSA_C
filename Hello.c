#include <stdio.h>

int search(int key, int arr[], int n) {
    // iterate through the array
    for(int i = 0; i < n; i++) {
        // if key found, return index
        if(arr[i] == key) {
            return i;
        }
    }
    // key not found, return -1
    return -1;
}

int main() {
    int n, key;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the key value to search: ");
    scanf("%d", &key);
    int result = search(key, arr, n);
    if(result == -1) {
        printf("Key not found in the array.\n");
    } else {
        printf("Key found at index %d.\n", result);
    }
   return 0;
}
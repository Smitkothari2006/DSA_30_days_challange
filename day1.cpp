#include <iostream>
using namespace std;

// Function to sort the array using the Dutch National Flag algorithm
void sortColors(int arr[], int n) {
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                swap(arr[low++], arr[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid], arr[high--]);
                break;
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    if (n == 0) {
        cout << "[]\n";
        return;
    }

    cout << "[";
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i != n - 1) cout << ", ";
    }
    cout << "]\n";
}

int main() {
    // Test Case 1
    int arr1[] = {0, 1, 2, 1, 0, 2, 1, 0};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    sortColors(arr1, n1);
    printArray(arr1, n1); // Expected: [0, 0, 0, 1, 1, 1, 2, 2]

    // Test Case 2
    int arr2[] = {2, 2, 2, 2};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    sortColors(arr2, n2);
    printArray(arr2, n2); // Expected: [2, 2, 2, 2]

    // Test Case 3
    int arr3[] = {0, 0, 0, 0};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    sortColors(arr3, n3);
    printArray(arr3, n3); // Expected: [0, 0, 0, 0]

    // Test Case 4
    int arr4[] = {1, 1, 1, 1};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    sortColors(arr4, n4);
    printArray(arr4, n4); // Expected: [1, 1, 1, 1]

    // Test Case 5
    int arr5[] = {2, 0, 1};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    sortColors(arr5, n5);
    printArray(arr5, n5); // Expected: [0, 1, 2]

    // Test Case 6: Empty Array
    int arr6[] = {};
    int n6 = 0;
    sortColors(arr6, n6);
    printArray(arr6, n6); // Expected: []

    return 0;
}

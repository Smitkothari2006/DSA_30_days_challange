/*
Merge Two Sorted Arrays

You are given two sorted arrays arr1 of size m and arr2 of size n. 
Your task is to merge these two arrays into a single sorted array 
without using any extra space (i.e., in-place merging). 

The elements in arr1 should be merged first, followed by the elements of arr2, 
resulting in both arrays being sorted after the merge.

Input:
Two sorted integer arrays arr1 of size m and arr2 of size n.

Example: 
Input: arr1 = [1, 3, 5, 7], arr2 = [2, 4, 6, 8]
Output: arr1 = [1, 2, 3, 4], arr2 = [5, 6, 7, 8]

Constraints:
- The arrays are sorted in non-decreasing order.
- You must not use any extra space beyond a few variables (O(1) space complexity).
- 1 ≤ m, n ≤ 10^5.
- 1 ≤ arr1[i], arr2[j] ≤ 10^9.
*/

#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate the next gap
int nextGap(int gap) {
    if (gap <= 1) return 0;
    return (gap / 2) + (gap % 2);
}

// In-place merge function using the gap method
void merge(int arr1[], int m, int arr2[], int n) {
    int gap = nextGap(m + n);

    while (gap > 0) {
        int i = 0, j = gap;

        while (j < m + n) {
            int a, b;

            if (i < m) a = arr1[i];
            else a = arr2[i - m];

            if (j < m) b = arr1[j];
            else b = arr2[j - m];

            if (a > b) {
                if (i < m && j < m) {
                    swap(arr1[i], arr1[j]);
                } else if (i < m && j >= m) {
                    swap(arr1[i], arr2[j - m]);
                } else {
                    swap(arr2[i - m], arr2[j - m]);
                }
            }

            i++;
            j++;
        }

        gap = nextGap(gap);
    }
}

int main() {
    int m, n;

    cout << "Enter size of arr1: ";
    cin >> m;
    int arr1[m];
    cout << "Enter " << m << " sorted elements for arr1: ";
    for (int i = 0; i < m; i++) {
        cin >> arr1[i];
    }

    cout << "Enter size of arr2: ";
    cin >> n;
    int arr2[n];
    cout << "Enter " << n << " sorted elements for arr2: ";
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    merge(arr1, m, arr2, n);

    cout << "After merging:\n";
    cout << "arr1 = ";
    for (int i = 0; i < m; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2 = ";
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}

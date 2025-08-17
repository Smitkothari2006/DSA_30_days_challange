/*
Find the Duplicate Number

You are given an array arr containing n+1 integers, where each integer is in the range [1, n] inclusive.
There is exactly one duplicate number in the array, but it may appear more than once.

Your task is to find the duplicate number without modifying the array and using constant extra space.

Input:
An integer array arr of size n+1, where each element is an integer in the range [1, n].
Example : arr = [3, 1, 3, 4, 2]

Output:
Return the duplicate integer present in the array.
Example: Duplicate number: 3

Constraints:
1 ≤ n ≤ 10^5.
There is only one duplicate number, but it may appear more than once.
You must not modify the array (arr) or use extra space greater than O(1).
The time complexity must be O(n).

Test Cases:
Test Case 1:
Input: [1, 3, 4, 2, 2]
Output: 2

Test Case 2:
Input: [3, 1, 3, 4, 2]
Output: 3

Test Case 3:
Input: [1, 1]
Output: 1

Test Case 4:
Input: [1, 4, 4, 2, 3]
Output: 4

Test Case 5:
Input: [1, 2, 3, ..., 99999, 50000]
Output: 50000

Edge Cases:
The smallest possible array with n = 1 where both elements are the same.
Arrays where the duplicate number appears more than twice.
*/

#include <iostream>
using namespace std;

int findDuplicate(const int arr[], int size) {
    int slow = arr[0];
    int fast = arr[0];

    // First phase: detect cycle
    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    // Second phase: find entrance to the cycle (duplicate)
    slow = arr[0];
    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}

int main() {
    // Example input
    int arr[] = {3, 1, 3, 4, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "\nDuplicate number: " << findDuplicate(arr, size) << endl<<endl;
    return 0;
}

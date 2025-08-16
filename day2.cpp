/*
    Problem: Find the Missing Number

    You are given an array `arr` containing n-1 distinct integers.
    The array consists of integers taken from the range 1 to n,
    meaning one integer is missing from this sequence.
    Your task is to find the missing integer.

    Input:
    - First line: an integer n (the upper bound of the range 1 to n).
    - Second line: n-1 distinct integers from the range [1, n].

    Output:
    - The missing integer from the array.

    Constraints:
    - The array contains exactly n-1 distinct integers.
    - All integers are in the range [1, n].
    - Time Complexity: O(n)
    - Space Complexity: O(1)
    - 1 ≤ n ≤ 10^6

    Example:
    Input:
    5
    1 2 4 5
    Output:
    Missing number: 3
*/

#include <iostream>

using namespace std;

int findMissingNumber(int arr[], int n) {
    long long expected_sum = (long long)n * (n + 1) / 2;
    long long actual_sum = 0;

    for (int i = 0; i < n - 1; ++i) {
        actual_sum += arr[i];
    }

    return expected_sum - actual_sum;
}

int main() {
    int n;

    cout << "Enter the value of n (total numbers from 1 to n): ";
    cin >> n;

    if (n < 2) {
        cout << "Invalid input. n must be at least 2." << endl;
        return 1;
    }

    int* arr = new int[n - 1];  // Dynamically allocate array of size n-1

    cout << "Enter " << n - 1 << " distinct numbers from 1 to " << n << ":" << endl;
    for (int i = 0; i < n - 1; ++i) {
        cin >> arr[i];
    }

    int missing = findMissingNumber(arr, n);
    cout << "Missing number: " << missing << endl;

    delete[] arr;  // Free allocated memory
    return 0;
}

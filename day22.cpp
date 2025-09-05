#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
First Element to Repeat k Times

You are given an array of integers and an integer k. 
Your task is to find the first element in the array that appears exactly k times. 
If no such element exists, return -1.

Input:
- An integer array arr of size n, where 1 ≤ n ≤ 10^5
- An integer k, where 1 ≤ k ≤ n

Output:
- Return the first element from the array that occurs exactly k times.
- If no element occurs exactly k times, return -1.

Examples:

Input: arr = [3, 1, 4, 4, 5, 2, 6, 1, 4], k = 2
Output: 1

Input: arr = [2, 3, 4, 2, 2, 5, 5], k = 2
Output: 5

Input: arr = [1, 1, 1, 1], k = 1
Output: -1

Input: arr = [10], k = 1
Output: 10

Input: arr = [6, 6, 6, 6, 7, 7, 8, 8, 8], k = 3
Output: 8
*/

int firstElementToRepeatKTimes(const vector<int>& arr, int k) {
    unordered_map<int, int> freq;

    // Count frequencies
    for (int num : arr) {
        freq[num]++;
    }

    // Find first element with frequency == k
    for (int num : arr) {
        if (freq[num] == k) {
            return num;
        }
    }

    return -1;
}

int main() {
    int n, k;
    cout << "Enter the number of elements in the array (n): ";
    cin >> n;

    if (n < 1 || n > 100000) {
        cout << "Invalid input. n must be between 1 and 100000.\n";
        return 0;
    }

    vector<int> arr(n);
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the value of k (1 <= k <= n): ";
    cin >> k;

    if (k < 1 || k > n) {
        cout << "Invalid input. k must be between 1 and " << n << ".\n";
        return 0;
    }

    int result = firstElementToRepeatKTimes(arr, k);
    cout << "Output: " << result << endl;

    return 0;
}

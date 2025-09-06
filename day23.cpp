/*
Sliding Window Maximum

You are given an array of integers `arr` and a positive integer `k`.
Your task is to find the maximum element in each sliding window of size `k`.

The window slides from left to right, one element at a time.
Return an array of size `n−k+1` containing the maximum element from each window.

Constraints:
- 1 ≤ n ≤ 10^5
- 1 ≤ k ≤ n
- Elements can be positive, negative, or zero

Examples:
Input:  arr = [1, 3, -1, -3, 5, 3, 6, 7], k = 3
Output: [3, 3, 5, 5, 6, 7]

Edge Cases:
- Single Element Array
- Window Size 1
- Array with All Same Elements
*/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// Function to compute sliding window maximum
vector<int> slidingWindowMaximum(const vector<int>& arr, int k) {
    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < arr.size(); ++i) {
        // Remove indices out of window
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Remove smaller elements from the back
        while (!dq.empty() && arr[dq.back()] < arr[i])
            dq.pop_back();

        dq.push_back(i);

        // Store max in result when window is full
        if (i >= k - 1)
            result.push_back(arr[dq.front()]);
    }

    return result;
}

// Helper function to print a vector
void printVector(const vector<int>& vec) {
    for (int num : vec)
        cout << num << " ";
    cout << endl;
}

int main() {
    // ---- User Input ----
    int n, k;
    cout << "Enter the size of the array (n): ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter window size (k): ";
    cin >> k;

    if (k > n || k < 1) {
        cout << "Invalid window size. Must be between 1 and n.\n";
        return 1;
    }

    // ---- Compute and Print Result ----
    vector<int> result = slidingWindowMaximum(arr, k);
    cout << "Sliding Window Maximums: ";
    printVector(result);

    return 0;
}

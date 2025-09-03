/*
    Problem: Sort a Stack Using Recursion

    Given a stack of integers, sort the stack in ascending order using recursion.
    You are NOT allowed to use any additional data structures (arrays, vectors, lists, queues, or another stack).
    You can only use standard stack operations: push, pop, top, and empty.

    Goal:
    - After sorting, the smallest elements should be at the top of the stack.
    - The stack should be sorted in ascending order using only recursion.
    - The output should display the stack from BOTTOM to TOP (like a sorted array).
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Function to insert an element in a sorted stack
void insertSorted(stack<int>& s, int element) {
    if (s.empty() || s.top() <= element) {
        s.push(element);
        return;
    }

    int top = s.top();
    s.pop();
    insertSorted(s, element);
    s.push(top);
}

// Recursive function to sort the stack
void sortStack(stack<int>& s) {
    if (s.empty()) return;

    int top = s.top();
    s.pop();
    sortStack(s);
    insertSorted(s, top);
}

// Function to recursively store elements from bottom to top
void storeBottomToTop(stack<int>& s, vector<int>& result) {
    if (s.empty()) return;

    int top = s.top();
    s.pop();
    storeBottomToTop(s, result);
    result.push_back(top); // Bottom elements go in first
    s.push(top); // Restore the stack
}

// Print the stack from bottom to top
void printStackBottomToTop(stack<int>& s) {
    vector<int> result;
    storeBottomToTop(s, result);

    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i != result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    stack<int> s;
    int n, val;

    cout << "Enter the number of elements in the stack: ";
    cin >> n;

    if (n <= 0) {
        cout << "Original Stack (Bottom to Top): []\n";
        cout << "Sorted Stack (Bottom to Top): []\n";
        return 0;
    }

    cout << "Enter " << n << " integers (top element first):\n";

    // Read into temporary array to reverse the order
    vector<int> temp(n);
    for (int i = 0; i < n; ++i) {
        cin >> temp[i];
    }

    // Push into stack in reverse order
    for (int i = n - 1; i >= 0; --i) {
        s.push(temp[i]);
    }

    cout << "Original Stack (Bottom to Top): ";
    printStackBottomToTop(s);

    sortStack(s);

    cout << "Sorted Stack (Bottom to Top): ";
    printStackBottomToTop(s);

    return 0;
}

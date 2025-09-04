/*
Problem: Reverse a Stack Using Recursion

You are given a stack of integers, and your task is to write a function that reverses the stack using recursion.
You are not allowed to use any additional data structure (like arrays, lists, or another stack).
The only operations you are allowed to perform are push, pop, and peek (top) on the stack.
The reversal must be done using recursion only.

Input:
A stack of integers. The stack may contain positive, negative, or zero values.

Output:
The stack should be reversed, meaning the element that was at the bottom of the original stack
should become the topmost element after the reversal.

Examples:
Input: [1, 2, 3, 4]         Output: [4, 3, 2, 1]
Input: [3, 2, 1]            Output: [1, 2, 3]
Input: [5]                 Output: [5]
Input: [-5, -10, -15]      Output: [-15, -10, -5]
Input: []                  Output: []
Input: [3, 3, 3]           Output: [3, 3, 3]

Constraints:
- No additional data structures allowed.
- Only stack operations and recursion.
- Input size up to 10^4 elements.

Edge Cases:
- Single Element: remains the same after reversal.
- Empty Stack: no operation is needed.
- All Elements Same: order will not change.
- Negative Numbers: must be handled correctly.
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Function to insert element at the bottom of the stack
void insertAtBottom(stack<int>& stk, int val) {
    if (stk.empty()) {
        stk.push(val);
        return;
    }

    int top = stk.top();
    stk.pop();
    insertAtBottom(stk, val);
    stk.push(top);
}

// Recursive function to reverse the stack
void reverseStack(stack<int>& stk) {
    if (stk.empty()) return;

    int top = stk.top();
    stk.pop();
    reverseStack(stk);
    insertAtBottom(stk, top);
}

// Utility function to print stack from top to bottom
void printStack(stack<int> stk) {
    vector<int> temp;
    while (!stk.empty()) {
        temp.push_back(stk.top());
        stk.pop();
    }

    cout << "[";
    for (int i = 0; i < temp.size(); ++i) {
        cout << temp[i];
        if (i != temp.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Main
int main() {
    vector<vector<int>> testCases = {
        {1, 2, 3, 4},
        {3, 2, 1},
        {5},
        {-5, -10, -15},
        {},
        {3, 3, 3}
    };

    for (int i = 0; i < testCases.size(); ++i) {
        stack<int> stk;
        for (int j = testCases[i].size() - 1; j >= 0; --j) {
            stk.push(testCases[i][j]); // insert elements in order
        }

        cout << "Test Case " << i + 1 << " - Original Stack: ";
        printStack(stk);

        reverseStack(stk);

        cout << "Reversed Stack: ";
        printStack(stk);
        cout << "-----------------------------\n";
    }

    // User Input
    stack<int> userStack;
    int n, val;
    cout << "Enter number of elements in the stack: ";
    cin >> n;

    cout << "Enter elements (top to bottom): ";
    vector<int> userInput(n);
    for (int i = n - 1; i >= 0; --i) {
        cin >> userInput[i];
    }
    for (int i = 0; i < n; ++i) {
        userStack.push(userInput[i]);
    }

    cout << "User Stack Before Reversing: ";
    printStack(userStack);

    reverseStack(userStack);

    cout << "User Stack After Reversing: ";
    printStack(userStack);

    return 0;
}

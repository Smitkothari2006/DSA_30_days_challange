#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
    Problem: Valid Parentheses with Multiple Types

    You are given a string s consisting of different types of parentheses: (), {}, and [].
    Your task is to determine whether the given string is valid.

    A string is considered valid if:
    - Every opening bracket has a corresponding closing bracket of the same type.
    - The brackets are closed in the correct order. 
      This means that a closing bracket must close the most recent unmatched opening bracket.

    Input:
    - A string s consisting of characters (, ), {, }, [, and ].

    Output:
    - Return true if the string is valid.
    - Return false if the string is invalid.

    Constraints:
    - 0 ≤ s.length ≤ 10^4
    - The string s contains only the characters ()[]{}.

    Test Cases:
    Input: s = "()"         → Output: true
    Input: s = "([)]"       → Output: false
    Input: s = "[{()}]"     → Output: true
    Input: s = ""           → Output: true
    Input: s = "{[}"        → Output: false

    Edge Cases:
    - Empty string: Should return true.
    - Odd length string: Cannot be valid, return false.
    - Unmatched closing brackets: If string starts with a closing bracket, it's invalid.
*/

bool isValid(string s) {
    stack<char> st;
    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else {
            if (st.empty()) return false;
            char top = st.top();
            if ((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '[')) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string input;
    cout << "Enter a string of parentheses: ";
    cin >> input;

    bool result = isValid(input);
    cout << "Output: " << (result ? "true" : "false") << endl;

    return 0;
}
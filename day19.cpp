#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

/*
Evaluate a Postfix Expression

Given a postfix expression (Reverse Polish Notation), evaluate and return the result.

Input:
- A string of integers and operators (+, -, *, /) separated by spaces.
- Only integers (positive/negative) and valid operators.
- Division is integer division truncating toward zero.

Output:
- Integer result of evaluation.

Examples:
Input: "2 1 + 3 *"       Output: 9
Input: "5 6 +"           Output: 11
Input: "3 4 2 * 1 5 - 2 3 ^ ^ / +" Output: -1
Input: "-5 6 -"          Output: -11
Input: "15 7 1 1 + - / 3 * 2 1 1 + + -" Output: 5
Input: "5"               Output: 5

Edge Cases:
- Single Operand: e.g., "42" → 42
- Negative Numbers: Supported
- Integer Division: Truncate toward zero
- Multiple Operations: Handled properly
*/

int evaluatePostfix(string expression) {
    stack<int> stk;
    stringstream ss(expression);
    string token;

    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = stk.top(); stk.pop();
            int a = stk.top(); stk.pop();
            int result = 0;

            if (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else if (token == "/") {
                // Truncate division toward zero
                result = a / b;
            }

            stk.push(result);
        } else {
            // Convert token to integer (handles negatives too)
            stk.push(stoi(token));
        }
    }

    return stk.top();
}

int main() {
    string input;
    cout << "Enter postfix expression: ";
    getline(cin, input);

    int result = evaluatePostfix(input);
    cout << "Output: " << result << endl;

    return 0;
}

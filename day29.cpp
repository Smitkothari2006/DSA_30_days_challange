/*
Fibonacci Sequence using Dynamic Programming

You are given an integer n. Your task is to calculate the n-th Fibonacci number using Dynamic Programming.
The Fibonacci sequence is a series of numbers where:
F(0) = 0
F(1) = 1
For n ≥ 2, F(n) = F(n−1) + F(n−2)

Your task is to compute F(n) efficiently by using a bottom-up dynamic programming approach, avoiding redundant calculations.

Input:
A single integer n (0 ≤ n ≤ 1000).

Output:
Return the n-th Fibonacci number.

Examples:
Input: 5
Output: 5

Input: 10
Output: 55

Input: 0
Output: 0

Input: 1000
Output: 43466557686937456435688527675040625802564660517371780402481729089536555417949051890403879840079255169295922593080322634775209689623239873322471161642996440906533187938298969649928516003704476137795166849228875
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to add two big integers represented as strings
string addBigNumbers(const string& a, const string& b) {
    string result;
    int carry = 0;
    int n = max(a.size(), b.size());

    // Pad with zeros
    string A = string(n - a.size(), '0') + a;
    string B = string(n - b.size(), '0') + b;

    // Add from right to left
    for (int i = n - 1; i >= 0; i--) {
        int sum = (A[i] - '0') + (B[i] - '0') + carry;
        carry = sum / 10;
        result += (sum % 10) + '0';
    }

    if (carry) result += carry + '0';

    reverse(result.begin(), result.end());
    return result;
}

// Function to calculate nth Fibonacci number using DP with big integers
string fibonacci(int n) {
    if (n == 0) return "0";
    if (n == 1) return "1";

    vector<string> fib(n + 1);
    fib[0] = "0";
    fib[1] = "1";

    for (int i = 2; i <= n; i++) {
        fib[i] = addBigNumbers(fib[i - 1], fib[i - 2]);
    }

    return fib[n];
}

int main() {
    int n;
    cout << "Enter an integer n (0 to n to 1000): ";
    cin >> n;

    if (n < 0 || n > 1000) {
        cout << "Invalid input. n must be between 0 and 1000." << endl;
        return 1;
    }

    string result = fibonacci(n);
    cout << "The " << n << "-th Fibonacci number is:\n" << result << endl;

    return 0;
}

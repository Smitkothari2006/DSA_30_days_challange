#include <iostream>
using namespace std;

/*
Problem: LCM (Least Common Multiple) of Two Numbers

You are given two integers, N and M. Your task is to find the Least Common Multiple (LCM) of these two numbers. 
The LCM of two integers is the smallest positive integer that is divisible by both N and M.

Input:
Two integers N and M, where 1 ≤ N, M ≤ 10^9

Output:
A single integer representing the Least Common Multiple of N and M.

Examples:
Input: N = 4, M = 6
Output: 12
Explanation: The smallest number divisible by both 4 and 6 is 12.

Test Cases:
Input: N = 4, M = 6           Output: 12
Input: N = 5, M = 10          Output: 10
Input: N = 7, M = 3           Output: 21
Input: N = 1, M = 987654321   Output: 987654321
Input: N = 123456, M = 789012 Output: 8117355456

Edge Cases:
- One number is 1: The LCM of any number with 1 is the number itself.
- Both numbers are equal: If N == M, then LCM is N (or M).
- Large numbers: Handle large inputs efficiently using the Euclidean algorithm for computing GCD.
*/

// Function to compute GCD using Euclidean Algorithm
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute LCM using GCD
long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;  // Avoids overflow
}

int main() {
    long long N, M;

    cout << "Enter two integers N and M: ";
    cin >> N >> M;

    long long result = lcm(N, M);
    cout << "LCM: " << result << endl;

    return 0;
}

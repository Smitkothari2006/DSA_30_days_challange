/*
Prime Factorization of a Number

Given a positive integer N (2 ≤ N ≤ 10^9), find its prime factorization.
Return a list of prime numbers that multiply together to give N.
If N is prime, the output should be a list containing only N.

Examples:
Input: N = 18        Output: [2, 3, 3]
Input: N = 30        Output: [2, 3, 5]
Input: N = 49        Output: [7, 7]
Input: N = 19        Output: [19]
Input: N = 64        Output: [2, 2, 2, 2, 2, 2]
Input: N = 123456    Output: [2, 2, 2, 2, 2, 3, 643]

Edge Cases:
- N is a small prime number: 2, 3, 5 → should return [N]
- N is a perfect power of a prime: 27 → should return [3, 3, 3]
- N has large prime factors: e.g., 123457 → [123457] (if prime)
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to compute prime factorization
vector<int> primeFactorization(int n) {
    vector<int> factors;

    // Handle factor 2 separately
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    // Check for odd factors from 3 to sqrt(n)
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    // If remaining n is a prime number greater than 2
    if (n > 2)
        factors.push_back(n);

    return factors;
}

// Function to display the result
void printFactors(const vector<int>& factors) {
    cout << "[";
    for (size_t i = 0; i < factors.size(); ++i) {
        cout << factors[i];
        if (i != factors.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    int N;

    // User Input
    cout << "Enter a number (2 <= N <= 1e9): ";
    cin >> N;

    // Prime Factorization
    vector<int> result = primeFactorization(N);

    // Output Result
    cout << "Prime factors: ";
    printFactors(result);


    return 0;
}

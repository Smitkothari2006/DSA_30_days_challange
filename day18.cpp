/*
    Problem: Count the Number of Divisors of a Number

    Given a positive integer N (1 ≤ N ≤ 10^9), 
    find the total number of its positive divisors.

    A divisor of a number is any integer that divides the number evenly (without a remainder).

    Example:
    Input: N = 12
    Output: 6
    Explanation: Divisors are 1, 2, 3, 4, 6, 12

    Constraints:
    - 1 ≤ N ≤ 10^9
    - Time Complexity should be O(sqrt(N))

    Edge Cases Handled:
    - N = 1
    - N is a prime number
    - N is a perfect square
    - N is a very large number (up to 10^9)
*/

#include <iostream>
#include <cmath>

using namespace std;

int countDivisors(int N) {
    int count = 0;
    int sqrtN = sqrt(N);
    for (int i = 1; i <= sqrtN; ++i) {
        if (N % i == 0) {
            count += 2; // i and N/i are both divisors
            if (i == N / i) {
                count--; // if both are the same, count only once (perfect square)
            }
        }
    }
    return count;
}

int main() {
    int N;
    cout << "Enter a number: ";
    cin >> N;

    int result = countDivisors(N);
    cout << "Number of divisors: " << result << endl;

    return 0;
}

/*
========================================
🪙 Coin Change Problem
========================================
You are given an array of integers 'coins' of size 'n', where each element 
represents the denomination of a coin. You are also given an integer 'amount',
representing the total amount of money. 

🔸 Objective:
Return the **minimum number of coins** required to make up the given amount. 
If it is not possible to make up the amount, return -1.

🔹 Constraints:
- 1 ≤ n ≤ 12
- 0 ≤ amount ≤ 10^4
- Each coin value is a positive integer.

🔸 Examples:
Input: coins = [1, 2, 5], amount = 11
Output: 3
Explanation: 5 + 5 + 1 = 11 (minimum 3 coins)

Input: coins = [2], amount = 3
Output: -1 (no way to form 3 using only 2s)

Input: coins = [1], amount = 0
Output: 0 (no coins needed)

========================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to compute minimum number of coins to make the amount
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);  // Initialize with amount+1 (infinity)
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (coin <= i) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
    int n, amount;
    cout << "Enter number of coin denominations: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter the coin denominations:\n";
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    cout << "Enter the amount: ";
    cin >> amount;

    int result = coinChange(coins, amount);

    if (result != -1)
        cout << "Minimum number of coins required: " << result << endl;
    else
        cout << "Amount cannot be formed with the given coin denominations.\n";

    return 0;
}

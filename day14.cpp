/*
Count Substrings with Exactly K Distinct Characters

You are given a string s of lowercase English alphabets and an integer k. 
Your task is to count all possible substrings of s that contain exactly k distinct characters.

Input:
- A string s consisting of lowercase English letters.
- An integer k, where 1 ≤ k ≤ 26
- The length of the string satisfies 1 ≤ n ≤ 10^4

Output:
- Return an integer that represents the number of substrings of s that contain exactly k distinct characters.

Examples:
Input: s = "pqpqs", k = 2
Output: 7

Input: s = "aabacbebebe", k = 3
Output: 10

Input: s = "a", k = 1
Output: 1

Input: s = "abc", k = 3
Output: 1

Input: s = "abc", k = 2
Output: 2

Edge Cases:
- If k = 1, count the number of substrings with only one distinct character.
- If k > n, return 0.
- If the string consists of repeated characters, substrings depend on repeated character count.
*/

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Helper function to count substrings with at most K distinct characters
int countSubstringsWithAtMostKDistinct(string& s, int k) {
    int left = 0, right = 0;
    int count = 0;
    unordered_map<char, int> freq;

    while (right < s.length()) {
        freq[s[right]]++;

        while (freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) {
                freq.erase(s[left]);
            }
            left++;
        }

        count += right - left + 1;
        right++;
    }

    return count;
}

// Main function to count substrings with exactly K distinct characters
int countSubstringsWithExactlyKDistinct(string& s, int k) {
    if (k > s.length()) return 0;
    return countSubstringsWithAtMostKDistinct(s, k) - countSubstringsWithAtMostKDistinct(s, k - 1);
}

int main() {
    string s;
    int k;

    cout << "Enter the string: ";
    cin >> s;

    cout << "Enter the value of k: ";
    cin >> k;

    int result = countSubstringsWithExactlyKDistinct(s, k);
    cout << "Output: " << result << endl;

    return 0;
}

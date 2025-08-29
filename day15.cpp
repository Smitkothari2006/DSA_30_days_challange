/*
Problem: Longest Substring Without Repeating Characters

You are given a string S, and your task is to find the length of the longest substring that contains no repeating characters.
A substring is a contiguous block of characters in the string.

Input:
A string S, where 1 ≤ |S| ≤ 10^5 (length of string).

Output:
An integer representing the length of the longest substring without repeating characters.

Examples:
Input: S = "abcabcbb"   => Output: 3 ("abc")
Input: S = "bbbbb"      => Output: 1 ("b")
Input: S = "pwwkew"     => Output: 3 ("wke")
Input: S = "abcdefgh"   => Output: 8 ("abcdefgh")
Input: S = "a"          => Output: 1 ("a")

Edge Cases:
- Single character string: The longest substring without repeating characters is the character itself.
- All characters are unique: If no characters repeat, the entire string is the longest substring.
- All characters are the same: If all characters are identical, the longest substring will be of length 1.
*/

#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

// Function to find the length of the longest substring without repeating characters
int lengthOfLongestSubstring(const string& s) {
    unordered_set<char> charSet;
    int left = 0, maxLength = 0;

    for (int right = 0; right < s.length(); ++right) {
        while (charSet.find(s[right]) != charSet.end()) {
            charSet.erase(s[left]);
            ++left;
        }
        charSet.insert(s[right]);
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}


int main() {
    string s;

    cout << "Enter a string to find the length of the longest substring without repeating characters:\n";
    getline(cin, s);

    int result = lengthOfLongestSubstring(s);
    cout << "Length of the longest substring without repeating characters: " << result << endl;

    // Run predefined test cases

    return 0;
}

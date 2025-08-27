#include <iostream>
#include <string>
using namespace std;

// Function to expand around center and return the longest palindrome
string expandAroundCenter(const string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        --left;
        ++right;
    }
    return s.substr(left + 1, right - left - 1);
}

// Function to find the longest palindromic substring
string longestPalindrome(string s) {
    if (s.empty()) return "";

    string longest = s.substr(0, 1); // At least one character is a palindrome

    for (int i = 0; i < s.size(); ++i) {
        // Odd-length palindrome
        string p1 = expandAroundCenter(s, i, i);
        if (p1.length() > longest.length()) longest = p1;

        // Even-length palindrome
        string p2 = expandAroundCenter(s, i, i + 1);
        if (p2.length() > longest.length()) longest = p2;
    }

    return longest;
}

// ---------- Main Function ----------
int main() {
    cout << "Enter a string to find the longest palindromic substring:\n";
    string input;
    getline(cin, input);

    string result = longestPalindrome(input);
    cout << "Longest Palindromic Substring: " << result << endl;

    // // Hidden internal test cases for validation (no output)
    // string testCases[] = {"babad", "cbbd", "a", "aaaa", "abc", "abacdfgdcaba", "abcd", "aaabaaaa"};
    // string expected[]  = {"bab",   "bb",   "a", "aaaa", "a",   "aba",   "a",   "aaabaaa"};

    // for (int i = 0; i < sizeof(testCases)/sizeof(testCases[0]); ++i) {
    //     string output = longestPalindrome(testCases[i]);
    //     // Could add assert here if needed
    // }

    return 0;
}

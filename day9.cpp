#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
Longest Common Prefix

You are given an array of strings strs[], consisting of lowercase letters. Your task is to find the longest common prefix shared among all the strings. 
If there is no common prefix, return an empty string "".

A common prefix is a substring that appears at the beginning of all the strings in the array. The task is to identify the longest such prefix that all strings share.

Input:
An array of strings strs[] where each string consists of lowercase English letters.

Output:
A string representing the longest common prefix. If no common prefix exists, return an empty string "".
*/

string longestCommonPrefix(const vector<string>& strs) {
    if (strs.empty()) return "";
    if (strs.size() == 1) return strs[0];

    string prefix = strs[0];

    for (int i = 1; i < (int)strs.size(); ++i) {
        int j = 0;
        while (j < (int)prefix.size() && j < (int)strs[i].size() && prefix[j] == strs[i][j]) {
            j++;
        }
        prefix = prefix.substr(0, j);
        if (prefix.empty()) return "";
    }

    return prefix;
}

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);
    cout << "Enter " << n << " strings (lowercase only):\n";
    for (int i = 0; i < n; ++i) {
        cin >> strs[i];
    }

    string result = longestCommonPrefix(strs);

    cout << "Longest Common Prefix: \"" << result << "\"\n";

    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

/*
Permutations of a String

You are given a string s. Your task is to generate and return all possible permutations
of the characters in the string. A permutation is a rearrangement of the characters
in the string, and each character must appear exactly once in every permutation.
If there are duplicate characters in the string, the resulting permutations should
also be unique (i.e., no repeated permutations).

Input:
A string s consisting of lowercase English letters. The length of the string n satisfies 1 ≤ n ≤ 9.

Output:
An array of strings containing all unique permutations of the input string.
The order of permutations in the output does not matter.

Examples:
Input: "abc"
Output: ["abc", "acb", "bac", "bca", "cab", "cba"]

Input: "aab"
Output: ["aab", "aba", "baa"]

Input: "aaa"
Output: ["aaa"]

Input: "a"
Output: ["a"]

Input: "abcd"
Output: ["abcd", "abdc", ..., "dcba"]

Edge Cases:
- Single character string: If the input string has only one character, the output will be the string itself.
- All characters the same: If all characters in the string are identical, there will be only one unique permutation.
- String contains duplicate characters: The output must not contain duplicate permutations.
*/

void backtrack(string &s, vector<bool> &used, string &current, vector<string> &result) {
    if (current.size() == s.size()) {
        result.push_back(current);
        return;
    }

    for (int i = 0; i < s.size(); ++i) {
        if (used[i]) continue;
        // Skip duplicates
        if (i > 0 && s[i] == s[i - 1] && !used[i - 1]) continue;

        used[i] = true;
        current.push_back(s[i]);
        backtrack(s, used, current, result);
        current.pop_back();
        used[i] = false;
    }
}

vector<string> getUniquePermutations(string s) {
    sort(s.begin(), s.end()); // Sort to handle duplicates
    vector<string> result;
    vector<bool> used(s.size(), false);
    string current;
    backtrack(s, used, current, result);
    return result;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    vector<string> permutations = getUniquePermutations(s);

    cout << "Unique permutations:\n";
    for (const string &perm : permutations) {
        cout << perm << "\n";
    }

    return 0;
}
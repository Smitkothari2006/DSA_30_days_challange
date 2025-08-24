#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
Problem: Group Anagrams

You are given an array of strings strs[]. Your task is to group all the strings that are anagrams of each other. 
An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using 
all the original letters exactly once.

Input:
An array of strings strs[] consisting of lowercase English letters.

Output:
A list of lists, where each sublist contains strings that are anagrams of each other. 
The order of the output groups does not matter.

Constraints:
1 ≤ strs.length ≤ 10^4
0 ≤ strs[i].length ≤ 100
All strings consist of lowercase English letters.
*/

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramMap;
    
    for (const string& s : strs) {
        string sortedStr = s;
        sort(sortedStr.begin(), sortedStr.end()); // Sort characters to form the key
        anagramMap[sortedStr].push_back(s);
    }
    
    vector<vector<string>> result;
    for (auto& pair : anagramMap) {
        result.push_back(pair.second);
    }
    
    return result;
}

// Utility function to print groups
void printGroups(const vector<vector<string>>& groups) {
    cout << "[\n";
    for (const auto& group : groups) {
        cout << "  [";
        for (size_t j = 0; j < group.size(); ++j) {
            cout << "\"" << group[j] << "\"";
            if (j < group.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }
    cout << "]\n";
}

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);
    cout << "Enter " << n << " strings:\n";
    for (int i = 0; i < n; ++i) {
        cin >> strs[i];
    }

    vector<vector<string>> result = groupAnagrams(strs);

    cout << "\nGrouped Anagrams:\n";
    printGroups(result);

    return 0;
}


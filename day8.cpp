
/*
Problem: Reverse a String Word by Word

You are given a string `s` that consists of multiple words separated by spaces.
Your task is to reverse the order of the words in the string.

Requirements:
- Words are sequences of non-space characters.
- Remove leading and trailing spaces.
- Reduce multiple spaces between words to a single space.
- Return the reversed words joined by a single space.

Examples:
Input:  "the sky is blue"           → Output: "blue is sky the"
Input:  "  hello world  "           → Output: "world hello"
Input:  "a good   example"          → Output: "example good a"
Input:  "    "                      → Output: ""
Input:  "word"                      → Output: "word"

Constraints:
- 1 ≤ s.length ≤ 10^4
- s may contain leading or trailing spaces.
- Words are separated by one or more spaces.
- s contains printable ASCII characters.
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to reverse words in a string
string reverseWords(string s) {
    istringstream iss(s);
    string word;
    vector<string> words;

    // Extract words, skipping extra spaces
    while (iss >> word) {
        words.push_back(word);
    }

    // Reverse the order of words
    reverse(words.begin(), words.end());

    // Join words with a single space
    ostringstream oss;
    for (size_t i = 0; i < words.size(); ++i) {
        if (i != 0) oss << ' ';
        oss << words[i];
    }

    return oss.str();
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);  // Take full line input from user

    string output = reverseWords(input);
    cout << "Reversed words: \"" << output << "\"" << endl;

    return 0;
}

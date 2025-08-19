#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findLeaders(const vector<int>& arr) {
    int n = arr.size();
    vector<int> leaders;
    int maxFromRight = arr[n - 1];

    leaders.push_back(maxFromRight);

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > maxFromRight) {
            maxFromRight = arr[i];
            leaders.push_back(arr[i]);
        }
    }

    reverse(leaders.begin(), leaders.end());
    return leaders;
}

void printLeaders(const vector<int>& leaders) {
    cout << "Leaders: ";
    for (int num : leaders) {
        cout << num << " ";
    }
    cout << "\n";
}

int main() {
    vector<vector<int>> testCases = {
        {16, 17, 4, 3, 5, 2},
        {1, 2, 3, 4, 0},
        {7, 10, 4, 10, 6, 5, 2},
        {5},
        {100, 50, 20, 10}
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";
        vector<int> leaders = findLeaders(testCases[i]);
        printLeaders(leaders);
    }

    return 0;
}

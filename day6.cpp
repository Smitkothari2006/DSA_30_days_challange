#include <iostream>
using namespace std;

const int MAXN = 100000;  // Max array size

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    long long arr[MAXN];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Result arrays to store start and end indices of subarrays
    int start[MAXN], end[MAXN];
    int result_count = 0;

    // Try every subarray
    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];

            if (sum == 0) {
                start[result_count] = i;
                end[result_count] = j;
                result_count++;
            }
        }
    }

    // Output the result
    if (result_count == 0) {
        cout << "[]\n";
    } else {
        cout << "Subarrays with zero sum:\n";
        for (int i = 0; i < result_count; i++) {
            cout << "(" << start[i] << ", " << end[i] << ")\n";
        }
    }

    return 0;
}

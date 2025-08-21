#include <iostream>
using namespace std;

/*
    Problem: Trapping Rain Water

    You are given an array height[] of non-negative integers where each element represents the height of a bar in a histogram-like structure. These bars are placed next to each other, and the width of each bar is 1 unit. When it rains, water gets trapped between the bars if there are taller bars on both the left and right of the shorter bars. The task is to calculate how much water can be trapped between these bars after the rain.

    The amount of water trapped above any bar is determined by the difference between the height of the bar and the minimum height of the tallest bars on its left and right.

    Example:
    Input: height[] = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    Output: 6

    Constraints:
    1 ≤ height.length ≤ 2 × 10^5
    0 ≤ height[i] ≤ 10^4

    Edge Cases:
    - All bars have height 0: No water trapped.
    - Array with less than 3 bars: No water trapped.
    - Strictly increasing or decreasing: No water trapped.
*/

// Function to calculate trapped rainwater
int trapRainWater(int height[], int n) {
    if (n < 3) return 0; // No space to trap water

    int left = 0, right = n - 1;
    int left_max = 0, right_max = 0;
    int water_trapped = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= left_max)
                left_max = height[left];
            else
                water_trapped += left_max - height[left];
            left++;
        } else {
            if (height[right] >= right_max)
                right_max = height[right];
            else
                water_trapped += right_max - height[right];
            right--;
        }
    }

    return water_trapped;
}

// Test cases
int main() {
    // Test Case 1
    int height1[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n1 = sizeof(height1) / sizeof(height1[0]);
    cout << "Output: " << trapRainWater(height1, n1) <<  endl;

    // Test Case 2
    int height2[] = {4, 2, 0, 3, 2, 5};
    int n2 = sizeof(height2) / sizeof(height2[0]);
    cout << "Output: " << trapRainWater(height2, n2) <<  endl;

    // Test Case 3
    int height3[] = {1, 1, 1};
    int n3 = sizeof(height3) / sizeof(height3[0]);
    cout << "Output: " << trapRainWater(height3, n3) << endl;

    // Test Case 4
    int height4[] = {5};
    int n4 = sizeof(height4) / sizeof(height4[0]);
    cout << "Output: " << trapRainWater(height4, n4) <<  endl;

    // Test Case 5
    int height5[] = {2, 0, 2};
    int n5 = sizeof(height5) / sizeof(height5[0]);
    cout << "Output: " << trapRainWater(height5, n5)  << endl;

    return 0;
}

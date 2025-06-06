// Problem 1480: Running Sum of 1D Array
// Link: https://leetcode.com/problems/running-sum-of-1d-array/
// Description: Given an array nums, return the running sum of nums.
// Running sum at index i = sum of all elements from index 0 to i.

// Time Complexity: O(n), where n is the size of the array
// Space Complexity: O(1) (in-place modification)

#include <iostream>
#include <vector>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
    for (int i = 1; i < nums.size(); ++i) {
        nums[i] += nums[i - 1];
    }
    return nums;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = runningSum(nums);

    cout << "Running sum: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

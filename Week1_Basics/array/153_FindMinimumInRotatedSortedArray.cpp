#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        // If the array is not rotated (already sorted)
        if (nums[low] <= nums[high]) {
            return nums[low];
        }

        // Binary Search to find the minimum
        while (low < high) {
            int mid = low + (high - low) / 2;

            // If mid element is greater than the rightmost element,
            // then the minimum lies in the right half
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                // Else, the minimum is in the left half (including mid)
                high = mid;
            }
        }

        // When low == high, it points to the minimum element
        return nums[low];
    }
};

int main() {
    Solution solution;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    int minimum = solution.findMin(nums);
    cout << "Minimum element in the rotated sorted array: " << minimum << endl;

    return 0;
}
// Output: Minimum element in the rotated sorted array: 0
// Time Complexity: O(log n), where n is the number of elements in the array
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find the indices of two numbers that add up to the target
vector<int> twoSum(vector<int>& nums, int target) {
    // Create a map to store numbers we've seen and their corresponding indices
    unordered_map<int, int> map;  // key: number, value: index

    // Loop through each element in the array
    for (int i = 0; i < nums.size(); i++) {
        int current = nums[i];                 // Current number in the array
        int complement = target - current;     // The number we need to find

        // Check if complement is already in the map
        if (map.find(complement) != map.end()) {
            // If found, return the pair of indices:
            // index of complement and index of current number
            return {map[complement], i};
        }

        // Otherwise, store the current number with its index in the map
        map[current] = i;
    }

    // If no solution is found (though problem guarantees one), return empty vector
    return {};
}

// Main function to test the twoSum function
int main() {
    vector<int> nums = {2, 7, 11, 15};  // Input array
    int target = 9;                     // Target sum

    // Call the function and get result
    vector<int> result = twoSum(nums, target);

    // Print the result
    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}

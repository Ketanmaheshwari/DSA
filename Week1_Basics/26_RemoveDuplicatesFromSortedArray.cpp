#include <iostream>
#include <vector>
using namespace std;

// Function to remove duplicates in-place
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0; // If array is empty

    int i = 0;  // pointer for the unique part

    // Traverse the array starting from second element
    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;  // Move i forward
            nums[i] = nums[j];  // Copy the non-duplicate element
        }
    }

    // i is index of last unique element → length is i+1
    return i + 1;
}

int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    int newLength = removeDuplicates(nums);

    cout << "New length: " << newLength << endl;
    cout << "Modified array: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

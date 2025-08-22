/*
Leetcode 344: Reverse String

📝 Problem:
Given an array of characters, reverse it in-place using O(1) extra space.

📥 Example:
Input: ['h','e','l','l','o']
Output: ['o','l','l','e','h']

💡 Approach:
- Use two-pointer technique:
    1. Start pointer at index 0
    2. End pointer at last index
    3. Swap characters at start and end
    4. Move pointers toward center
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0;
        int end = s.size() - 1;

        while (start < end) {
            // Swap characters
            swap(s[start], s[end]);

            // Move pointers inward
            start++;
            end--;
        }
    }
};

// Optional main function for testing
int main() {
    Solution sol;
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    sol.reverseString(s);

    for (char c : s) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
// Output: o l l e h
// The output will be the reversed string: o l l e h
/*
Leetcode 1910: Remove All Occurrences of a Substring

📝 Problem:
Remove all occurrences of 'part' from string 's' repeatedly until it no longer exists.

🔧 Approach:
- Use a loop and string::find() to locate each occurrence.
- Remove the substring using erase().
- Repeat until no more occurrence is found.

⏱ Time: O(n * m), where n = length of s, m = length of part.
📦 Space: O(1) extra (in-place modification).
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        // Keep removing 'part' from 's' until not found
        while (s.find(part) != string::npos) {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};

// Optional main function for testing
int main() {
    Solution sol;
    string s = "daabcbaabcbc";
    string part = "abc";

    string result = sol.removeOccurrences(s, part);
    cout << "Result: " << result << endl;  // Output should be "dab"

    return 0;
}

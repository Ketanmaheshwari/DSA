/*
Leetcode 125: Valid Palindrome

📝 Problem Statement:
Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

A palindrome is a word, phrase, or sequence that reads the same backward as forward.

📥 Example 1:
Input: "A man, a plan, a canal: Panama"
Output: true

📥 Example 2:
Input: "race a car"
Output: false

🔧 Constraints:
- 1 <= s.length <= 2 * 10^5
- s consists only of printable ASCII characters.

💡 Approach:
1. Use two pointers (start and end) to scan the string from both ends.
2. Skip characters that are not alphanumeric using isalnum().
3. Compare lowercase characters using tolower().
4. If any mismatch found, return false.
5. If loop completes, return true.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length() - 1;

        while (start < end) {
            // Skip non-alphanumeric characters from the start
            while (start < end && !isalnum(s[start])) {
                start++;
            }

            // Skip non-alphanumeric characters from the end
            while (start < end && !isalnum(s[end])) {
                end--;
            }

            // Compare characters after converting to lowercase
            if (tolower(s[start]) != tolower(s[end])) {
                return false; // Mismatch found → not a palindrome
            }

            // Move both pointers inward
            start++;
            end--;
        }

        // All characters matched → it is a palindrome
        return true;
    }
};

// Optional main function for local testing
int main() {
    Solution sol;
    string testStr = "A man, a plan, a canal: Panama";
    bool result = sol.isPalindrome(testStr);
    
    cout << (result ? "True" : "False") << endl;
    return 0;
}
// This code defines a class Solution with a method isPalindrome that checks if a given string is a valid palindrome
// by ignoring non-alphanumeric characters and case differences. The main function tests this method with a sample input.
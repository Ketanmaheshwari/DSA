#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
    Problem: Reverse Words in a String
    -----------------------------------
    Given a string s, reverse the order of words.

    Example:
    Input: "daa bcb aabc bc"
    Output: "bc aabc bcb daa"

    Explanation:
    - First word = "daa"
    - Last word = "bc"
    After reversing order → "bc aabc bcb daa"
*/

class Solution {
public:
    string reverseWord(string s) {
        // Step 1: Reverse the whole string
        reverse(s.begin(), s.end());

        string ans = "";  // final result

        // Step 2: Process word by word
        for (int i = 0; i < s.length(); i++) {
            string word = "";

            // Collect characters until space
            while (i < s.length() && s[i] != ' ') {
                word += s[i];
                i++;
            }

            // Reverse the word back to its correct order
            reverse(word.begin(), word.end());

            // Add it to the answer if not empty
            if (word.length() > 0) {
                ans += " " + word;
            }
        }

        // Remove leading space before returning
        return ans.substr(1);
    }
};

// Driver code
int main() {
    Solution sol;

    string s = "the sky is blue";   // input string

    string result = sol.reverseWord(s);

    cout << "Result: " << result << endl;  
    // Expected Output: "bc aabc bcb daa"

    return 0;
}

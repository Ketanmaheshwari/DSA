//Time complexity is O(n^2)
#include <iostream>   // For input-output operations
#include <string>     // For using the string class
using namespace std;

/*
    LeetCode 567: Permutation in String
    -----------------------------------
    Problem:
    Given two strings s1 and s2, return true if s2 contains 
    a permutation of s1. Otherwise, return false.

    A permutation means rearranging characters. 
    So, if s1 = "ab", we check if s2 contains "ab" or "ba".
    
    Example:
    Input: s1 = "ab", s2 = "eidbaooo"
    Output: true
    Explanation: s2 contains "ba" which is a permutation of s1.
*/

class Solution {
public:
    // Function to check if two frequency arrays are same
    // freq1 and freq2 are arrays of size 26 (for lowercase a-z)
    bool isFreqSame(int freq1[], int freq2[]) {
        for (int i = 0; i < 26; i++) {        // loop through all alphabets
            if (freq1[i] != freq2[i]) {       // if frequency mismatches
                return false;                 // return false immediately
            }
        }
        return true;  // If all frequencies match, return true
    }

    // Main function to check if s2 contains any permutation of s1
    bool checkInclusion(string s1, string s2) {
        // Step 1: Store frequency of characters in s1
        int freq[26] = {0};                    // initialize all counts as 0
        for (int i = 0; i < s1.length(); i++) {
            freq[s1[i] - 'a']++;              // increase count of current character
        }

        int windSize = s1.length();           // size of the sliding window

        // Step 2: Slide a window of size 's1.length()' over s2
        for (int i = 0; i <= s2.length() - windSize; i++) {
            int windFreq[26] = {0};           // frequency array for current window

            // Step 3: Count characters in the current window
            for (int j = 0; j < windSize; j++) {
                windFreq[s2[i + j] - 'a']++;  // count character at position (i+j)
            }

            // Step 4: Compare the window's frequency with s1's frequency
            if (isFreqSame(freq, windFreq)) {
                return true;                  // Found a matching permutation
            }
        }

        // Step 5: If no window matched, return false
        return false;
    }
};

// Driver code for testing
int main() {
    Solution sol;  

    string s1 = "ab";           // smaller string to permute
    string s2 = "eidbaooo";     // larger string to check inside

    // Call the function
    bool result = sol.checkInclusion(s1, s2);

    // Print result in user-friendly way
    cout << "Does s2 contain any permutation of s1? "
         << (result ? "Yes" : "No") << endl;

    return 0;   // program ends successfully
}




// Time complexity is O(n)
#include <iostream>   // For input-output
#include <string>     // For using string class
using namespace std;

/*
    LeetCode 567: Permutation in String
    -----------------------------------
    Optimized Sliding Window Approach (O(n))

    Idea:
    - Count frequency of chars in s1.
    - Use a sliding window of size = s1.length() on s2.
    - Maintain frequency of the window:
        * Add the new char (entering window)
        * Remove the old char (leaving window)
    - If at any step, window frequency == s1 frequency → return true.
*/

class Solution {
public:
    // Function to compare two frequency arrays (O(26) = O(1))
    bool isFreqSame(int freq1[], int freq2[]) {
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                return false;   // mismatch found
            }
        }
        return true;  // all match
    }

    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false; // edge case

        // Step 1: Build frequency of s1
        int freq1[26] = {0};
        for (char c : s1) {
            freq1[c - 'a']++;
        }

        // Step 2: Initialize frequency of first window in s2
        int freq2[26] = {0};
        int windowSize = s1.length();

        for (int i = 0; i < windowSize; i++) {
            freq2[s2[i] - 'a']++;
        }

        // Step 3: Slide the window over s2
        for (int i = 0; i <= s2.length() - windowSize; i++) {
            // Compare window with s1
            if (isFreqSame(freq1, freq2)) {
                return true;   // found a permutation
            }

            // Slide window: remove s2[i], add s2[i + windowSize]
            if (i + windowSize < s2.length()) {
                freq2[s2[i] - 'a']--;                   // remove outgoing char
                freq2[s2[i + windowSize] - 'a']++;      // add incoming char
            }
        }

        return false;  // no permutation found
    }
};

// Driver code
int main() {
    Solution sol;

    string s1 = "ab";           // smaller string
    string s2 = "eidbaooo";     // larger string

    bool result = sol.checkInclusion(s1, s2);

    cout << "Does s2 contain any permutation of s1? "
         << (result ? "Yes" : "No") << endl;

    return 0;
}

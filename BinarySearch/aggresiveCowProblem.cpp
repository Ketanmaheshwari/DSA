/*
Aggressive Cows Problem:

Given N stalls at positions given in an array, and C cows.
Assign C cows to N stalls such that the minimum distance between any two cows is as large as possible.

Constraints:
1. Each stall can have at most one cow
2. Cows must be assigned to stalls
3. We want to maximize the minimum distance between any two cows

Example:
Input: stalls = [1, 2, 4, 8, 9], cows = 3
Output: 3
Explanation: 
Place cows at positions 1, 4, 8 or 1, 4, 9
Minimum distance = min(3, 4) = 3 or min(3, 5) = 3

Approach:
1. Sort the stalls array (crucial for binary search approach)
2. Use binary search on possible distance values (1 to max_distance)
3. For each candidate distance, check if we can place all cows with at least that distance
4. If possible, try larger distances; else try smaller distances

Time Complexity: O(N log(max_distance)) 
Space Complexity: O(1)
*/

#include<iostream>
#include<vector>
#include<algorithm> // Required for sort function
#include<climits>
using namespace std;

/**
 * Checks if it's possible to place all cows with given minimum distance
 * @param arr: Sorted array of stall positions
 * @param n: Number of stalls
 * @param c: Number of cows
 * @param minAllowedDistance: Minimum distance required between any two cows
 * @return: True if placement possible, False otherwise
 */
bool isPossible(vector<int> &arr, int n, int c, int minAllowedDistance) {
    int cowsPlaced = 1; // Place first cow at first stall
    int lastStallPosition = arr[0]; // Position of last placed cow
    
    for(int i = 1; i < n; i++) {
        // Check if current stall is at least minAllowedDistance away from last placed cow
        if(arr[i] - lastStallPosition >= minAllowedDistance) {
            cowsPlaced++; // Place a cow here
            lastStallPosition = arr[i]; // Update last placed position
            
            // If all cows are placed, return true
            if(cowsPlaced == c) {
                return true;
            }
        }
    }
    return false; // Could not place all cows
}

/**
 * Main function to find largest minimum distance between cows
 * @param arr: Array of stall positions
 * @param n: Number of stalls
 * @param c: Number of cows
 * @return: Largest minimum distance possible
 */
int largestMinDistance(vector<int> &arr, int n, int c) {
    // Sort the array first - CRUCIAL STEP
    sort(arr.begin(), arr.end());
    
    // Edge cases
    if(c > n) return -1; // More cows than stalls
    if(c < 2) return 0;  // Need at least 2 cows to calculate distance
    
    // Binary search boundaries
    int st = 1; // Minimum possible distance
    int end = arr[n-1] - arr[0]; // Maximum possible distance
    int ans = -1;
    
    while(st <= end) {
        int mid = st + (end - st) / 2;
        
        if(isPossible(arr, n, c, mid)) {
            // Possible to place with this distance, try for larger distance
            ans = mid;
            st = mid + 1;
        } else {
            // Not possible, try smaller distance
            end = mid - 1;
        }
    }
    
    return ans;
}

int main() {
    // Test cases
    vector<int> stalls1 = {1, 2, 4, 8, 9};
    int cows1 = 3;
    cout << "Test Case 1:" << endl;
    cout << "Stalls: [1, 2, 4, 8, 9], Cows: " << cows1 << endl;
    cout << "Largest minimum distance: " << largestMinDistance(stalls1, stalls1.size(), cows1) << endl;
    cout << "Expected: 3" << endl << endl;
    
    vector<int> stalls2 = {1, 2, 8, 4, 9};
    int cows2 = 3;
    cout << "Test Case 2:" << endl;
    cout << "Stalls: [1, 2, 8, 4, 9], Cows: " << cows2 << endl;
    cout << "Largest minimum distance: " << largestMinDistance(stalls2, stalls2.size(), cows2) << endl;
    cout << "Expected: 3" << endl << endl;
    
    vector<int> stalls3 = {1, 2, 3};
    int cows3 = 2;
    cout << "Test Case 3:" << endl;
    cout << "Stalls: [1, 2, 3], Cows: " << cows3 << endl;
    cout << "Largest minimum distance: " << largestMinDistance(stalls3, stalls3.size(), cows3) << endl;
    cout << "Expected: 2" << endl;
    
    return 0;
}

//Total time complexity: O(N log N + N log(max_distance))
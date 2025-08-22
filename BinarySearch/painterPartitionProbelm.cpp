/*
Painter's Partition Problem:

Given N boards of different lengths (array of lengths) and M painters.
Each painter takes 1 unit of time to paint 1 unit of board.
The constraint is that any painter will only paint continuous sections of boards.

Task: Find the minimum time required to paint all the boards under these constraints.

Constraints:
1. Each painter must paint at least one board
2. Each board must be painted by exactly one painter
3. A painter can only paint contiguous boards
4. The goal is to minimize the maximum time taken by any painter

Example:
Input: boards = [10, 20, 30, 40], painters = 2
Output: 60
Explanation: 
Painter 1: [10, 20, 30] = 60 units
Painter 2: [40] = 40 units
Maximum time = max(60, 40) = 60

Approach:
We use binary search to find the minimum possible maximum time taken by any painter.
The search space ranges from the maximum board length to the total sum of all board lengths.

Time Complexity: O(N log(Sum)) where N is number of boards and Sum is total length
Space Complexity: O(1)
*/

#include<iostream>
#include<vector>
#include<climits> // For INT_MIN
using namespace std;

/**
 * Checks if it's possible to paint all boards within given maximum time per painter
 * @param boards: Array containing lengths of boards
 * @param n: Number of boards
 * @param painters: Number of painters available
 * @param maxTimePerPainter: Maximum time allowed per painter
 * @return: True if painting is possible, False otherwise
 */
bool isPossibleToPaint(vector<int> &boards, int n, int painters, int maxTimePerPainter) {
    int paintersRequired = 1;  // Start with first painter
    int currentTime = 0;       // Time taken by current painter so far
    
    for(int i = 0; i < n; i++) {
        // If any single board is longer than maxTimePerPainter, it's impossible
        if(boards[i] > maxTimePerPainter) {
            return false;
        }
        
        // Check if current board can be assigned to current painter
        if(currentTime + boards[i] <= maxTimePerPainter) {
            currentTime += boards[i];  // Assign board to current painter
        } else {
            paintersRequired++;        // Need a new painter
            currentTime = boards[i];   // New painter starts with current board
            
            // If we require more painters than available, it's impossible
            if(paintersRequired > painters) {
                return false;
            }
        }
    }
    return true;  // All boards can be painted within constraints
}

/**
 * Main function to find minimum time to paint all boards
 * @param boards: Array containing lengths of boards
 * @param n: Number of boards
 * @param painters: Number of painters available
 * @return: Minimum time required or -1 if not possible
 */
int findMinimumTime(vector<int> &boards, int n, int painters) {
    // Edge case: If no boards, no time needed
    if(n == 0) return 0;
    
    // If more painters than boards, allocation not possible as per constraints
    if(painters > n) {
        return -1;
    }
    
    int totalLength = 0;
    int maxBoardLength = INT_MIN;
    
    // Calculate total length and find the longest board
    for(int i = 0; i < n; i++) {
        totalLength += boards[i];
        maxBoardLength = max(maxBoardLength, boards[i]);
    }
    
    // Binary search boundaries:
    int start = maxBoardLength;  // Minimum possible time (time for longest board)
    int end = totalLength;       // Maximum possible time (one painter does all)
    int result = -1;
    
    while(start <= end) {
        int mid = start + (end - start) / 2;  // Current candidate for maximum time per painter
        
        if(isPossibleToPaint(boards, n, painters, mid)) {
            // Valid allocation found, try for smaller time
            result = mid;
            end = mid - 1;
        } else {
            // Need more time per painter
            start = mid + 1;
        }
    }
    
    return result;
}

int main() {
    // Test cases
    vector<int> boards1 = {10, 20, 30, 40};
    int painters1 = 2;
    cout << "Test Case 1:" << endl;
    cout << "Boards: [10, 20, 30, 40], Painters: " << painters1 << endl;
    cout << "Minimum time: " << findMinimumTime(boards1, boards1.size(), painters1) << endl;
    cout << "Expected: 60" << endl << endl;
    
    vector<int> boards2 = {7, 10, 15, 10};
    int painters2 = 2;
    cout << "Test Case 2:" << endl;
    cout << "Boards: [7, 10, 15, 10], Painters: " << painters2 << endl;
    cout << "Minimum time: " << findMinimumTime(boards2, boards2.size(), painters2) << endl;
    cout << "Expected: 25" << endl << endl;
    
    vector<int> boards3 = {5, 5, 5, 5};
    int painters3 = 3;
    cout << "Test Case 3:" << endl;
    cout << "Boards: [5, 5, 5, 5], Painters: " << painters3 << endl;
    cout << "Minimum time: " << findMinimumTime(boards3, boards3.size(), painters3) << endl;
    cout << "Expected: 10" << endl << endl;
    
    return 0;
}
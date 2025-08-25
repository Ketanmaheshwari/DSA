/*
===========================================================
Problem: Sort an array containing only 0s, 1s, and 2s
Approach: Dutch National Flag (single pass, in-place)

Core idea:
We maintain three regions using pointers low, mid, high:

    [0 .. low-1]     -> all 0s (sorted)
    [low .. mid-1]   -> all 1s (sorted)
    [mid .. high]    -> unknown / unprocessed
    [high+1 .. n-1]  -> all 2s (sorted)

Initialize:
    low = 0, mid = 0, high = n-1

Process while (mid <= high):
    Case a[mid] == 0:
        - Put 0 into the 0s region by swapping a[low] and a[mid]
        - Expand 0s region and processed window:
              low++, mid++

    Case a[mid] == 1:
        - 1 is already in its correct region (middle), just move mid:
              mid++

    Case a[mid] == 2:
        - Put 2 into the 2s region by swapping a[mid] and a[high]
        - Shrink 2s region from the right:
              high--
        - DO NOT increment mid here because the element swapped in from a[high]
          is unprocessed; we must inspect it in the next loop iteration.

Complexity:
    Time  : O(n) — each element is moved at most a constant number of times.
    Space : O(1) — in-place.
Assumptions:
    The array contains only 0, 1, and 2.
===========================================================
*/

#include <iostream>
#include <vector>
#include <algorithm> // for std::swap
using namespace std;

void sortColors(vector<int>& a) {
    int n = static_cast<int>(a.size());
    int low = 0, mid = 0, high = n - 1;

    // Invariants during the loop:
    // a[0 .. low-1]   = 0s
    // a[low .. mid-1] = 1s
    // a[mid .. high]  = unknown
    // a[high+1 .. n-1]= 2s
    while (mid <= high) {
        if (a[mid] == 0) {
            // Place 0 into the 0s region and advance both low and mid
            swap(a[low], a[mid]);
            ++low;
            ++mid;
        } else if (a[mid] == 1) {
            // 1 is already in the correct middle region; just move forward
            ++mid;
        } else { // a[mid] == 2
            // Place 2 into the 2s region; don't advance mid yet
            swap(a[mid], a[high]);
            --high;
        }
    }
}

// Helper to print the array (for quick verification)
static void printVec(const vector<int>& v) {
    for (int x : v) cout << x << ' ';
    cout << '\n';
}

int main() {
    vector<int> arr = {2, 0, 2, 1, 1, 0, 1, 2, 0, 0};
    sortColors(arr);
    printVec(arr); // Expected: 0 0 0 0 1 1 1 2 2 2
    return 0;
}

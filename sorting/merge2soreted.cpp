/*
===========================================================
Problem: Merge Two Sorted Arrays
(LeetCode 88: Merge Sorted Array)

We are given two sorted arrays:
    A (size m + n), where the first m elements are valid
    B (size n), with n elements

Goal:
    Merge B into A such that A becomes a single sorted array
    of length m + n.

Approach:
    - Use three pointers:
        i   → points to the last valid element in A (m-1)
        j   → points to the last element in B (n-1)
        idx → points to the last index in A (m+n-1), 
               where the merged result will be placed

    - Compare A[i] and B[j]:
        • If A[i] >= B[j], put A[i] at A[idx] and move i--
        • Otherwise, put B[j] at A[idx] and move j--
        • Always move idx--

    - Continue until either i < 0 or j < 0
    - If elements remain in B, copy them into A (since A’s remaining
      elements are already in correct place)

Why backwards?
    - Because A already has size m+n but only first m elements are filled.
    - By filling from the end, we avoid overwriting unprocessed elements.

Complexity:
    Time  : O(m + n)  (each element is processed once)
    Space : O(1)      (in-place merge, no extra array)
===========================================================
*/

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& A, int m, vector<int>& B, int n) {
    int idx = m + n - 1;  // Last index of merged array
    int i = m - 1;        // Last valid element in A
    int j = n - 1;        // Last element in B

    // Merge from the back
    while (i >= 0 && j >= 0) {
        if (A[i] >= B[j]) {
            A[idx] = A[i];
            i--;
        } else {
            A[idx] = B[j];
            j--;
        }
        idx--;
    }

    // If any elements remain in B, copy them
    while (j >= 0) {
        A[idx] = B[j];
        j--;
        idx--;
    }
}

// Helper to print array
void printVec(const vector<int>& v) {
    for (int x : v) cout << x << ' ';
    cout << '\n';
}

int main() {
    // Example:
    vector<int> A = {1, 3, 5, 0, 0, 0}; // m=3 valid elements, size=6
    vector<int> B = {2, 4, 6};          // n=3 elements

    int m = 3, n = 3;
    merge(A, m, B, n);

    printVec(A); // Expected: 1 2 3 4 5 6
    return 0;
}

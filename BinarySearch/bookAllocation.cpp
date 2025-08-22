/*
Book Allocation Problem:

Given an array of books where each element represents the number of pages in a book,
and given the number of students (m), the task is to allocate books to students such that:
1. Each student gets at least one book
2. Each book should be allocated to exactly one student
3. Books must be allocated in contiguous order
4. The maximum number of pages allocated to any student should be minimized

If allocation is not possible, return -1.

Approach:
We use binary search to find the minimum possible maximum pages allocated to any student.
The search space ranges from 0 to the total sum of all pages.

For each candidate value (mid), we check if it's possible to allocate books such that
no student gets more than 'mid' pages. If possible, we try to find a smaller value
in the left half; otherwise, we search in the right half.

Time Complexity: O(n log(sum)) where n is number of books and sum is total pages
Space Complexity: O(1)
*/

#include<iostream>
#include<vector>
using namespace std;

/**
 * Checks if it's possible to allocate books with given constraints
 * @param arr: Array containing page counts of books
 * @param n: Number of books
 * @param m: Number of students
 * @param maxAllowedPages: Maximum pages allowed per student
 * @return: True if allocation is possible, False otherwise
 */
bool isValid(vector<int> &arr, int n, int m, int maxAllowedPages) {
    int studentsRequired = 1;  // Start with first student
    int currentPages = 0;      // Pages allocated to current student
    
    for(int i = 0; i < n; i++) {
        // If any single book exceeds maxAllowedPages, allocation not possible
        if(arr[i] > maxAllowedPages) {
            return false;
        }
        
        // If adding current book exceeds the limit, allocate to next student
        if(currentPages + arr[i] > maxAllowedPages) {
            studentsRequired++;        // Need one more student
            currentPages = arr[i];     // Start new allocation with current book
            
            // If we exceed the number of students, allocation not possible
            if(studentsRequired > m) {
                return false;
            }
        } else {
            // Add current book to current student's allocation
            currentPages += arr[i];
        }
    }
    return true;  // Allocation possible with given constraints
}

/**
 * Main function to find minimum possible maximum pages allocation
 * @param arr: Array containing page counts of books
 * @param n: Number of books
 * @param m: Number of students
 * @return: Minimum possible maximum pages or -1 if not possible
 */
int allocateBooks(vector<int> &arr, int n, int m) {
    // If students exceed books, allocation not possible
    if(m > n) {
        return -1;
    }
    
    int totalPages = 0;
    for(int i = 0; i < n; i++) {
        totalPages += arr[i];
    }
    
    int result = -1;
    int start = 0;
    int end = totalPages;
    
    while(start <= end) {
        int mid = start + (end - start) / 2;
        
        if(isValid(arr, n, m, mid)) {
            // Found a valid allocation, try for smaller value
            result = mid;
            end = mid - 1;
        } else {
            // Current mid is too small, need larger value
            start = mid + 1;
        }
    }
    return result;
}

int main() {
        vector<int> arr = {2, 1, 3, 4};
        int n = arr.size();
        int m = 2;
        cout << allocateBooks(arr, n, m) << endl;  // Expected output: 113
        return 0;
}
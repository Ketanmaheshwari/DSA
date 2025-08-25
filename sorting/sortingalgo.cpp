#include<iostream>
#include<vector>
using namespace std;

// ---------------------------
// Bubble Sort Algorithm
// ---------------------------
// Idea: Repeatedly swap adjacent elements if they are in the wrong order.
// After each iteration, the largest element "bubbles up" to the end.
// Time Complexity: O(n^2) in worst case, O(n) in best case (already sorted).
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool isSwap = false;  // To check if any swap happened in this iteration

        // Compare adjacent elements and swap if needed
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }

        // If no swap happened in this pass, array is already sorted → stop early
        if (!isSwap) {
            return;
        }
    }
}

// ---------------------------
// Selection Sort Algorithm
// ---------------------------
// Idea: Repeatedly find the minimum element from the unsorted part
// and put it at the beginning of the unsorted part.
// Time Complexity: O(n^2) in all cases.
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int smallestIdx = i; // Assume the first element of unsorted part is the smallest

        // Find the actual smallest element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[smallestIdx]) {
                smallestIdx = j; // Update smallest index
            }
        }

        // Swap the found minimum element with the first element of unsorted part
        swap(arr[i], arr[smallestIdx]);
    }
}

// ---------------------------
// Insertion Sort Algorithm
// ---------------------------
// Idea: Take one element at a time (curr) and insert it into its correct
// position among the already sorted elements on the left side.
// Time Complexity: O(n^2) in worst case, O(n) in best case (already sorted).
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int curr = arr[i];     // Element to be inserted
        int prev = i - 1;      // Last index of sorted part

        // Shift elements greater than 'curr' one step to the right
        while (prev >= 0 && arr[prev] > curr) {
            arr[prev + 1] = arr[prev];
            prev--;
        }

        // Place 'curr' at its correct position
        arr[prev + 1] = curr;
    }
}

// ---------------------------
// Utility function to print array
// ---------------------------
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ---------------------------
// Main function
// ---------------------------
int main() {
    int n = 5;
    int arr[] = {4, 1, 3, 2, 5};

    // Uncomment the sorting algorithm you want to test:
    // bubbleSort(arr, n);
    selectionSort(arr, n);
    // insertionSort(arr, n);

    // Print sorted array
    printArray(arr, n);

    return 0;
}

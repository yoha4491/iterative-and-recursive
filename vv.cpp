# iterative-and-recursive
#include <iostream>
using namespace std;

int iBs(int arr[], int size, int target) // iBs is represented by Iterative binary search
{
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Prevent overflow
        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            low = mid + 1; // Search the right half
        } else {
            high = mid - 1; // Search the left half
        }
    }

    return -1; // Target not found
}

int rBs(int arr[], int low, int high, int target) // rBs is represented by Recursive inary search
{
    if (low > high) {
        return -1; // Base case: target not found
    }

    int mid = low + (high - low) / 2; // Prevent overflow
    if (arr[mid] == target) {
        return mid; // Target found
    } else if (arr[mid] < target) {
        return rBs(arr, mid + 1, high, target); // Search right half
    } else {
        return rBs(arr, low, mid - 1, target); // Search left half
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15}; // Static array
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    int target = 7;

    // Iterative approach
    int iterativeResult = iBs(arr, size, target);
    if (iterativeResult != -1) {
        cout << "Target found at index (iterative): " << iterativeResult << endl;
    } else {
        cout << "Target not found (iterative)." << endl;
    }

    // Recursive approach
    int recursiveResult = rBs(arr, 0, size - 1, target);
    if (recursiveResult != -1) {
        cout << "Target found at index (recursive): " << recursiveResult << endl;
    } else {
        cout << "Target not found (recursive)." << endl;
    }

    return 0;
}
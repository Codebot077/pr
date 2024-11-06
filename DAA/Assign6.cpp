#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>   
using namespace std;

int deterministicComparisons = 0;
int randomizedComparisons = 0;

// Partition function for deterministic quicksort (last element as pivot)
int deterministicPartition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        deterministicComparisons++;
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Deterministic quicksort function
void deterministicQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = deterministicPartition(arr, low, high);
        deterministicQuickSort(arr, low, pivotIndex - 1);
        deterministicQuickSort(arr, pivotIndex + 1, high);
    }
}

// Partition function for randomized quicksort (random element as pivot)
int randomizedPartition(vector<int>& arr, int low, int high) {
    int randomPivot = low + rand() % (high - low + 1);
    swap(arr[randomPivot], arr[high]); // Swap random pivot with last element

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        randomizedComparisons++;
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Randomized quicksort function
void randomizedQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = randomizedPartition(arr, low, high);
        randomizedQuickSort(arr, low, pivotIndex - 1);
        randomizedQuickSort(arr, pivotIndex + 1, high);
    }
}

// Utility function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0)); // Seed for random number generation

    // Sample array for testing
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    // Copy array for separate sorting
    vector<int> arrDeterministic = arr;
    vector<int> arrRandomized = arr;

    // Deterministic Quick Sort
    cout << "Deterministic Quick Sort:" << endl;
    deterministicQuickSort(arrDeterministic, 0, arrDeterministic.size() - 1);
    printArray(arrDeterministic);
    cout << "Number of comparisons (Deterministic): " << deterministicComparisons << endl;

    // Randomized Quick Sort
    cout << "\nRandomized Quick Sort:" << endl;
    randomizedQuickSort(arrRandomized, 0, arrRandomized.size() - 1);
    printArray(arrRandomized);
    cout << "Number of comparisons (Randomized): " << randomizedComparisons << endl;

    return 0;
}

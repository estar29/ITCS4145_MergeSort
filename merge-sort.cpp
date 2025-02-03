// Evan Stark - January 24th 2025 - ITCS 4145 001
// This C++ program simulates a basic Merge Sort Algorithm.
// It accomplishes this by recursively dividing the array in half until no longer
// and then rebuilds the arrays from least to greatest.
// 
// We will need to keep track of the lowest, middle, and highest index numbers to
// ensure the array is correctly halved.

// Needed imports.
#include <iostream>
#include <cstdlib>
#include <vector>
#include <chrono>

// SOURCES USED
// https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/?ref=header_outind
// https://www.geeksforgeeks.org/how-to-generate-random-number-in-range-in-cpp/
// https://www.geeksforgeeks.org/why-rand-function-always-give-the-same-value/
// https://www.youtube.com/watch?v=qB4ZQv-IVkk
// https://www.geeksforgeeks.org/cin-in-c/?ref=header_outind
// https://www.youtube.com/watch?v=4VqmGXwpLqc
// https://www.w3schools.com/cpp/cpp_function_array.asp
// https://www.tutorialspoint.com/cplusplus/cpp_return_arrays_from_functions.htm
// https://stackoverflow.com/questions/10290610/how-can-i-find-the-number-of-elements-in-an-array
// https://www.geeksforgeeks.org/cpp-pointers/?ref=gcse_outind
// https://takeuforward.org/data-structure/merge-sort-algorithm/
// https://stackoverflow.com/questions/22387586/measuring-execution-time-of-a-function-in-c
// https://godbolt.org/z/oe5cMd
// https://devdocs.io/cpp/header/chrono

// A brief ChatGPT discussion was held to attempt to debug segmentation faults.
// When this conversation occurred, I had spent roughly 1-1.5 hours on debugging this issue.
// https://chatgpt.com/share/679aad60-3bd8-8001-831d-e00a8827ead3

// ADDITIONAL CODE ASSISTANCE PROVIDED BY TA DAVASHISH BHAT DURING OFFICE HOURS //

using namespace std;

void merge(int* arr, int low, int mid, int high) {
    // Initialize a temporary array.
    // Vector is used here to take advantage of its array operations.
    vector<int> temp_array;

    // Get starting points of the left and right sub-arrays.
    int left = low;
    int right = mid+1;

    while(left <= mid && right <= high) {
        // If left size element <= to right side element --> put into array.
        if(arr[left] <= arr[right]) {
            temp_array.push_back(arr[left]);
            left++;
        }
        // Otherwise, put right side element in the array.
        else {
            temp_array.push_back(arr[right]);
            right++;
        }
    
    }

    // Put remaining left side elements in the sorted array.
    while(left <= mid) {
        temp_array.push_back(arr[left]);
        left++;
    }
    // Remaining right side elements put in the sorted array.
    while(right <= high) {
        temp_array.push_back(arr[right]);
        right++;
    }
    
    // Rebuilding the originial array.
    // Elements added in reverse.
    for (int a=high; a >= low; a--) {
        arr[a] = temp_array.back();
        temp_array.pop_back();
    }

}



void merge_sort(int* arr, int low, int high) {
    // Return if array has one element; i.e. low's index is greater/equal to than the high index.
    if (low >= high) {
        return;
    }
    
    // Calculate the middle index.
    int mid = (low + high) / 2;
        
    // Recursive call on the left half.
    merge_sort(arr,low, mid);
    // Recursive call on the right half.
    merge_sort(arr, mid+1, high);
    // Merge the halves together.
    merge(arr, low, mid, high);
}



// Function to generate data
void generate_data(int* arr, size_t n)
{
    // Call srand to ensure different output.
    srand(time(0));
    
    for(int i=0;i<n;i++)
    {
        // Cap elements from the integers 0-49.
        arr[i] = rand() % 50;
    }
}



// Main function for running the program.
int main() {
    int init_size;
    std::cout << "How many elements would you like to sort? \n";
    std::cin >> init_size;
    // Cap number of elements to 50.
    if(init_size > 50) {
        init_size = 50;
    }
    // Minimum of 4 elements.
    if (init_size < 4) {
        init_size = 4;
    }

    // Create the initial array.
    int* init_array = new int[init_size];
    generate_data(init_array, init_size);

    // Print out initial array.
    std::cout << "Initial array: ";
    for (int a=0; a < init_size; a++) {
        std::cout << init_array[a] << " ";
    }
    
    // Get the low and high indexes, and call merge_sort function.
    int low = init_size - init_size;
    int high = init_size - 1;

    // Calculating run-time.
    using std::chrono::high_resolution_clock;
    using std::chrono::duration;
    using std::chrono::duration_cast;
    using std::chrono::milliseconds;
    
    auto start_time = high_resolution_clock::now();
    merge_sort(init_array, low, high);
    auto end_time = high_resolution_clock::now();
    duration<double, std::milli> merge_duration = end_time - start_time;

    // Print sorted array.
    std::cout << "\nSorted array: ";
    for (int a=0; a < init_size; a++) {
        std::cout << init_array[a] << " ";
    }
    std::cout << "\n";

    std::cout << "\nTime taken = " << merge_duration.count() << " milliseconds";

    // Deallocate the array pointer.
    delete[] init_array;

    return 0;
}
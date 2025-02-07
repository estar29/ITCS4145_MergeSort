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
// https://www.geeksforgeeks.org/command-line-arguments-in-cpp/
// https://stackoverflow.com/questions/3054567/right-way-to-deallocate-an-stdvector-object

// CHATGPT Conversations about debugging segmentation faults and allocation errors.
// https://chatgpt.com/share/679aad60-3bd8-8001-831d-e00a8827ead3
// https://chatgpt.com/share/67a54947-5550-8001-849b-5030eb9aafee
// https://chatgpt.com/share/67a5679e-67b8-8001-b558-0c945d5a531e

// ADDITIONAL CODE ASSISTANCE PROVIDED BY TA DAVASHISH BHAT DURING OFFICE HOURS //

using namespace std;

void merge(size_t* arr, size_t low, size_t mid, size_t high) {
    // Initialize a temporary array.
    // Vector is used here to take advantage of its array operations.
    vector<size_t> temp_array;
    temp_array.reserve(1000);

    // Get starting points of the left and right sub-arrays.
    size_t left = low;
    size_t right = mid+1;

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
    for (size_t a= high + 1; a > low; a--) {
        arr[a] = temp_array.back();
        temp_array.pop_back();
    }
    
    // Ensuring memory is deallocated
    temp_array.clear();
}



void merge_sort(size_t* arr, size_t low, size_t high) {
    // Return if array has one element; i.e. low's index is greater/equal to than the high index.
    if (low >= high) {
        return;
    }
    
    // Calculate the middle index.
    size_t mid = (low + high) / 2;
        
    // Recursive call on the left half.
    merge_sort(arr,low, mid);
    // Recursive call on the right half.
    merge_sort(arr, mid+1, high);
    // Merge the halves together.
    merge(arr, low, mid, high);
}



// Function to generate data
void generate_data(size_t* arr, size_t n)
{
    // Call srand to ensure different output.
    srand(time(0));
    
    for(size_t i=0;i<n;i++)
    {
        // Cap elements from the integers 0-49.
        arr[i] = rand() % 50;
    }
}



// Main function for running the program and passing in arguments.
int main(int argc, char *argv[]) {
    // Create the initial array.
    // argv[1] will be the number of elements the user will want sorted.
    size_t init_size = (size_t) (argv[1]);
    size_t* init_array = new size_t[init_size];
    generate_data(init_array, init_size);
    
    // Get the low and high indexes, and call merge_sort function.
    size_t low = init_size - init_size;
    size_t high = init_size - 1;

    // Calculating run-time.
    using std::chrono::high_resolution_clock;
    using std::chrono::duration;
    using std::chrono::duration_cast;
    using std::chrono::milliseconds;
    
    auto start_time = high_resolution_clock::now();
    merge_sort(init_array, low, high);
    auto end_time = high_resolution_clock::now();
    duration<double, std::milli> merge_duration = end_time - start_time;

    std::cout << "\nTime taken = " << merge_duration.count() << " milliseconds\n";

    // Deallocate the array pointer.
    delete[] init_array;
    
    return 0;
}
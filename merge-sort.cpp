// Evan Stark - January 24th 2025 - ITCS 4145 001
// This C++ program simulates a basic Merge Sort Algorithm.

#include <iostream>
#include <cstdlib>

// SOURCES USED
// https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/?ref=header_outind
// https://www.geeksforgeeks.org/how-to-generate-random-number-in-range-in-cpp/
// https://www.youtube.com/watch?v=qB4ZQv-IVkk
// https://www.geeksforgeeks.org/cin-in-c/?ref=header_outind
// https://www.youtube.com/watch?v=4VqmGXwpLqc
// https://www.w3schools.com/cpp/cpp_function_array.asp
// https://www.tutorialspoint.com/cplusplus/cpp_return_arrays_from_functions.htm
// https://stackoverflow.com/questions/10290610/how-can-i-find-the-number-of-elements-in-an-array
// https://www.geeksforgeeks.org/cpp-pointers/?ref=gcse_outind

// A brief ChatGPT discussion was held to attempt to debug segmentation faults.
// When this conversation occurred, I had spent roughly 1-1.5 hours on debugging this issue.
// https://chatgpt.com/share/679aad60-3bd8-8001-831d-e00a8827ead3

using namespace std;

int* merge(int* arr_1, int* arr_2) {
    // Calculating the final size of the sorted array.
    int arr_1_size = (sizeof(arr_1) / sizeof(int));
    int arr_2_size = (sizeof(arr_2) / sizeof(int));
    int final_size = arr_1_size + arr_2_size;
    // Initialize the sorted array.
    int* sorted_array = new int[final_size];
    
    // 
    int rebuild_arr_1_index = 0;
    int rebuild_arr_2_index = 0;
    int final_size_index = final_size - 1;

    while(rebuild_arr_1_index < arr_1_size && rebuild_arr_2_index < arr_2_size) {
        // If the
        if(arr_1[0] > arr_2[0]) {
            sorted_array[final_size_index] = arr_2[0];
            final_size_index--;
            // Rebuilding arr_2.
            for(int a=rebuild_arr_2_index; a < arr_2_size; a++) {
                arr_2[0] = arr_2[a];
            }
            // Increment the index to make next array smaller.
            rebuild_arr_2_index++;
        }

        else {
            sorted_array[final_size_index] = arr_1[0];
            final_size_index--;
            // Rebuilding arr_1.
            for(int a=rebuild_arr_1_index; a<arr_2_size; a++) {
                arr_1[0] = arr_1[a];
            }
            // Increment index to make next array smaller.
            rebuild_arr_1_index++;
        }
    
    }

    // Put remaining arr_1 elements in the sorted array.
    while(rebuild_arr_1_index < arr_1_size) {
        sorted_array[final_size_index] = arr_1[0];
        final_size_index--;
        // Same rebuilding logic as above.
        for(int a=rebuild_arr_1_index; a<arr_1_size; a++) {
            arr_1[0] = arr_1[a];
        }

    }
    // Remaining arr_2 elements put in the sorted array.
    while(rebuild_arr_2_index < arr_2_size) {
        sorted_array[final_size-1] = arr_2[0];
        // Same rebuilding logic as above.
        for(int a=rebuild_arr_2_index; a<arr_2_size; a++) {
            arr_2[0] = arr_2[a];
        }
        rebuild_arr_2_index++;
    }
    return sorted_array;
}



int* merge_sort(int* arr) {
    // Getting the size of the array.
    int size = sizeof(arr) / sizeof(int);
    // Pointer for the init_array to allocate space.
    int* init_array = new int[size];
    
    // Return if array has one element.
    if (size/2 == 1) {
        return init_array;
    }

    // Getting the size / 2 for splitting the array.
    int half_size = size / 2;
    int sec_half_size = 0;
    // Handling odd numbered amount of elements.
    if (size % 2 == 1) {
        sec_half_size = (size/2) + 1;
    }
    else {
        sec_half_size = size / 2;
    }
    
    // Initialize arrays.
    int* arr_1 = new int[half_size];
    int* arr_2 = new int [sec_half_size];

    // Populating the arrays.
    for(int a=0; a < half_size; a++){
        arr_1[a] = init_array[a];
    }
    for(int a=sec_half_size + 1; a < size; a++){
        arr_2[a] = init_array[a];
    }

    cout << "1st-half: " << half_size << "\n";      // DEBUG
    cout << "2nd half: " << sec_half_size <<"\n";   // DEBUG
        
    // Run a recursive call on both functions.
    arr_1 = merge_sort(arr_1);
    arr_2 = merge_sort(arr_2);

    // Call the merge function.
    int* merge_array = merge(arr_1, arr_2);
    return merge_array;
}

void generate_data(int* arr, size_t n)
{
    for(int i=0;i<n;i++)
    {
        arr[i]=rand();
    }
}



// Main function for running the program.
int main() {
    int init_size;
    std::cout << "How many elements would you like to sort? \n";
    std:cin >> init_size;
    // Cap number of elements to 50.
    if(init_size > 50) {
        init_size = 50;
    }
    // Minimum of 4 elements.
    if (init_size < 4) {
        init_size = 4;
    }

    //Initialize the array.
    int* init_array = new int[init_size];
    for (int a=0; a<init_size; a++) {
        // Get a number from 0 thru 49.
        int rng_element = rand() % 50;
        init_array[a] = rng_element;
    }


    // Print out initial array.
    std::cout << "Initial array: ";
    for (int a=0; a < init_size; a++) {
        std::cout << init_array[a] << " ";
    }
    
    // Pointer for the output/sorted array and print the output.
    int* output = new int [init_size];
    output = merge_sort(init_array);
    
    std::cout << "Sorted array: ";
    for (int a=0; a < init_size; a++) {
        std::cout << output[a] << " ";
    }

    return 0;
}
#include <iostream>

int binary_search(int* array, int low, int high, int needle) {
    // A binary search over the array, that finds the index of the needle.

    // Our new mid point
    int mid = low + (high-low)/2;

    // We found it! Return its index
    if (array[mid] == needle) {
        return mid;
    }

    // We have gotten to the bottom of the tree, and still haven't found it: it's not here.
    if (low == high) {
        return -1;
    }

    // If we are smaller then mid
    std::cout << "Recursion" << std::endl;
    if (array[mid] > needle) {
        return binary_search(array, low, mid, needle);
    } else {
        // If we are larger then mid
        return binary_search(array, mid+1, high, needle);
    }
}


int main() {

    size_t array_len = 10;
    int array[array_len] = {0};
    for (int i = 0; i< array_len; ++i) {
        array[i] = i*3;
    }

    std::cout << "Our array: " << std::endl;
    for (auto i : array){
        std::cout<< i << " ";
    }
    std::cout << std::endl;

    int needle = 0;
    int* haystack = &array[0];
    int needle_index = binary_search(haystack, 0, array_len, needle);
    if (needle_index > -1) {
        std::cout << "Index of needle " << needle << " is " << needle_index << std::endl;
    } else {
        std::cout <<"Needle " << needle << " is not present in the array" << std::endl;
    }

    return 0;
}
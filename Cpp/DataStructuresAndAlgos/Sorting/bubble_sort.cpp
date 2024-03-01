#include <iostream>

void bubble_sort(int* array, size_t array_len) {
    // Bubble sort algorithm: we cycle through the array, and if the current value
    // is smaller than the next, we swap them. We iterate through the algorithm
    // n times, where n is the length of the array, to ensure the whole thing is sorted.
    
    for (int j=0; j< array_len; ++j) { 
        int past = array[0];
        for (int i = 1 ; i < array_len-j; ++i){
            if (array[i] < past) {
                int temp = array[i];
                array[i] = past;
                array[i-1] = temp;
            }
            past = array[i];
        } 
    }
}

int main () {

    size_t array_len = 10;
    int array[array_len] = {0};
    for (int i = 0; i< array_len; ++i) {
        if (i%2 == 0){
            array[i] = i;
        } else {
            array[i] = i*3;
        }
    }

    std::cout << "Our array: " << std::endl;
    for (auto i : array){
        std::cout<< i << " ";
    }
    std::cout << std::endl;

    int* pArray = &array[0];
    bubble_sort(pArray, array_len);
    
    std::cout << "Our sorted array: " << std::endl;
    for (auto i: array){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;


}
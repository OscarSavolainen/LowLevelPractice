#include <iostream>
#include <numeric>

int linear_search(int needle, int* haystack, size_t array_len) {
    int needle_index;
    bool found = false;

    for (int i = 0; i < array_len; ++i) {
        if (needle == haystack[i]) {
            needle_index = i;
            found = true;
        }
    };

    if (!found) {
        return array_len+1;
    }

    return needle_index;
}

int main(){

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

    int needle = 3;
    int* haystack = &array[0];
    int needle_index = linear_search(needle, haystack, array_len);
    if (needle_index < array_len) {
        std::cout << "Index of needle " << needle << " is " << needle_index << std::endl;
    } else {
        std::cout <<"Needle " << needle << " is not present in the array" << std::endl;
    }


    return 0;
}
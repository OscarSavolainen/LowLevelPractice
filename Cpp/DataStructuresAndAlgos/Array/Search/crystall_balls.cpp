#include <iostream>
#include <cmath>


int find_ball_break(int* array, int array_len){
    int first_break = array_len-1;
    double sqrt_len = sqrt(array_len);
    int sqrt_len_int = static_cast<int>(sqrt_len);

    // 1st iteration, we jump sqrt(len) each time until we get to the first break.
    for (int i=0; i < sqrt_len_int+1; ++i){
        int jump_index = i*sqrt_len_int;
        if (jump_index > (array_len-1)) {
            first_break = jump_index - sqrt_len_int;
            break;
        }
        if (array[jump_index] == 1) {
            first_break = jump_index;
            break;
        }
    }

    // 2nd iteration, we go back to sqrt(length) before the break, and move forward again
    int new_start = first_break - sqrt_len_int; 
    for (int i= new_start; i < first_break+1; ++i){
        if (array[i] == 1) {
            return i;
        }
    }
    return -1;    
}


int main(){

    size_t array_len = 15;
    int ball_break = 3;
    int array[array_len] = {0};
    for (int i = 0; i< array_len; ++i) {
        if (i > ball_break-1) {
            array[i] = 1;
        } else {
            array[i] = 0;
        }
    }

    std::cout << "Our array: " << std::endl;
    for (auto i : array){
        std::cout<< i << " ";
    }
    std::cout << std::endl;

    int* pArray = &array[0];
    int ball_break_index = find_ball_break(pArray, array_len);

    if (ball_break_index > -1) {
        std::cout << "Ball broke at " << ball_break_index << std::endl;
    } else {
        std::cout <<"The ball cannot break sire." << std::endl;
    }
    return 0;
}
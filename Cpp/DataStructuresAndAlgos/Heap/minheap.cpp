#include <iostream>
#include <cmath>

void print(int* &array, int size){
    std::cout << "\nPrinting array: " << std::endl;
    for (int i = 0; i < size; ++i){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int getRightChild(int index) {
    int right_c_index = 2*index + 2; 
    return right_c_index;
}

int getLeftChild(int index) {
    int left_c_index = 2*index + 1; 
    return left_c_index;
}

int getParent(int index) {
    int parent_index = (index+1)/2 -1;
    return parent_index;
}

int getMinValForPair(int index, int* &array) {
    // Gets the minimum value between two adjacent heap elements that
    // have the same parent.
    if (index % 2 == 0) {
        return std::min(array[index], array[index-1]);
    } else {
        return std::min(array[index], array[index+1]);
    }
}

int getHeight(int index){
    return static_cast<int>(log2(static_cast<float>(index)));
}

int indexOfSmallerChild(int index_a, int index_b, int* &array) {
    if (array[index_a] < array[index_b]){
        return index_a;
    } else {
        return index_b;
    }
}

int pop(int index, int* &array, int size){
    // We start at the point of deletion (top), and bubble values up.
    int value = array[index];

    int parent_index = index;
    int child_index = index;
    while (child_index / 2 < size) {
        child_index = indexOfSmallerChild(getLeftChild(parent_index), getRightChild(parent_index), array);
        if (child_index > size-1){
            array[parent_index] = size*2;
        } else {
            array[parent_index] = array[child_index];
        }
        parent_index = child_index;
    }
    return value;
}

void insertion(int value, int* &array, int length){
    int insert_index =  length-1;
    int heap_height = getHeight(length);

    // We keep going up until we find a value the inserted value is larger than (or we get to the top)
    while ((value < getMinValForPair(insert_index, array)) && (insert_index > 0)){
        std::cout << "Value : " << value << "; smaller than: " << getMinValForPair(insert_index, array) << std::endl;
        insert_index = getParent(insert_index);
        std::cout << "Next Insert index: " << insert_index << std::endl;
    }

    // We insert the insertion value, and store the old value.
    int temp = array[insert_index]; // store the old value
    array[insert_index] = value; // insert new value



    // We swap the values back down to the bottom of the heap 
    int new_index = insert_index;
    int temp2 = 0;
    for (int i = getHeight(insert_index); i < heap_height; ++i ) {
        print(array, length);
        std::cout << "New index " << new_index << std::endl;
        new_index = getLeftChild(new_index); // index we'll take the place of
        if (new_index > (length-1)) {
            std::cout << "Exceeding array bounds" << std::endl;
            break;
        }
        std::cout << "New index " << new_index << std::endl;
        temp2 = array[new_index]; // value we'll need to move next iteration
        array[new_index] = temp; // we take the place of the value
        std::cout << temp << " took the place of " << temp2 << std::endl;
        temp = temp2;
    }
}

int main() {

    int size = 15;
    int array[size];
    // We leave one value of the array free for insertion
    for (int i = 0; i < size-1; ++i){
        array[i] = i;
    }
    array[size-1] = 1000;

    int* pArray = &array[0];
    print(pArray, size);


    pop(0, pArray, size);
    print(pArray, size);

    insertion(0, pArray, size-1);
    print(pArray, size);

    return 0;
}
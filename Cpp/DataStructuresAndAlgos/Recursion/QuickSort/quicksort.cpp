#include <iostream>
#include <vector>

void print_vec(std::vector<int> vec) {
    for (int i = 0; i <vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void quickSort(std::vector<int> &vec, int low, int high) {

    // If we're at the "bottom" and low==high, we return.
    if (low>=high) {
        return;
    }

    // We ensure that all values smaller than the chosen pivot value are to its left.
    int pivot = vec[high];
    int p = low; // pivot index
    int temp = 0;
    for (int i = low; i < high; ++i) {
        // If value smaller than pivot, we swap vec[i] and vec[p] and then increment p
        if (vec[i] < pivot) {
            temp = vec[p];
            vec[p] = vec[i];
            vec[i] = temp;
            ++p; 
        } 
        // If value larger than pivot, we don't swap and dont increment p.
    }

    // At the end, we swap the final vec[p] with the pivot value.
    temp = vec[p];
    vec[p] = vec[high];
    vec[high] = temp;

    // Call this recursively.
    quickSort(vec, low, p-1);
    quickSort(vec, p+1, high);

}

int main() {

    // Intiialise a non-sorted vector
    int size = 11;
    std::vector<int> vec = {0};

    for (int i = 0; i < size; ++i) {
        if (i%2 == 0) {
            vec.push_back(i*3);
        } else {
            vec.push_back(i);
        }
    }
    vec.push_back(0);

    std::cout << "Unsorted vec: " << std::endl;
    print_vec(vec);

    quickSort(vec, 0, vec.size()-1);

    std::cout << "Sorted vec: " << std::endl;
    print_vec(vec);



    return 0;
}
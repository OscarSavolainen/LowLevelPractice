#include <iostream>
#include <cmath>
#include <vector>
#include <memory> // Include the memory header for std::unique_ptr

std::unique_ptr<std::vector<int>> getRightNeighbours(int x) {
    int floor = pow(2, std::floor(log2(x)));
    int ceil = pow(2, std::ceil(log2(x)+1));

    auto vec = std::make_unique<std::vector<int>>(ceil-floor);

    for (int i = 0; i < (ceil-floor); ++i) {
        (*vec)[i] = floor + i;
    }

    return vec;
}

int getRightestNeighbour(std::vector<int>& input, std::unique_ptr<std::vector<int>> right_neighbours) {
    for (auto i: right_neighbours) {
        for (auto)
    }
}


int main () {

    std::vector<int> input = {1,2,3,4,5,0,7};


}
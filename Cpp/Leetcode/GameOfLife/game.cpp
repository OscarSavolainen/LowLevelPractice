#include <vector>
#include <iostream>

bool checkValidCell(int x, int y, int m, int n){
    /*
    Checks if the cell given by x and y is a valid cell (within the grid).
    */
    if (x<0 || x>=n || y<0 || y>=m) {
        return false;
    } else {
        return true;
    }
}

int sumNeighbours(int x, int y, std::vector<std::vector<int>> board, int m, int n) {
    /*
    We take the sum of all of the nighbours of cell [y][x]. This tell us how the cell shoudl be updated
    in the next iteration.
    */
    int neighbours = 0;
    for (int j = -1; j < 2; ++j) {
        for (int i = -1; i < 2; ++i){
            // This is the same call, not a neighbour
            if (i==0 && j==0) {
                continue;
            }
            bool valid_neighbour = checkValidCell(x+i, y+j, m, n);
            if (valid_neighbour) {
                neighbours+=board[y+j][x+i];
            }
        }
    }
    return neighbours;
}

void gameOfLife(std::vector<std::vector<int>>& board) {
    int m = board.size();
    int n = board[0].size();
    std::vector<std::vector<int>> new_board(m, std::vector<int>(n, 0));
    int x = 0;
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            int living_neighbours = sumNeighbours(x, y, board, m, n);
            if (board[y][x] == 1) {
                if (living_neighbours < 2 || living_neighbours > 3) {
                    new_board[y][x] = 0;
                } else {
                    new_board[y][x] = 1;
                }
            } else {
                if (living_neighbours == 3) {
                    new_board[y][x] = 1;
                }
            }
            
        }
    }

    for (int y = 0; y < m; ++y) {
        for (int x = 0; x < n; ++x) {
            board[y][x] = new_board[y][x];
        }
    }

    return;
}

int main () {
    int m = 4;
    int n = 3;

    std::vector<std::vector<int>> board   = {{0,1,0},
                                             {0,0,1},
                                             {1,1,1},
                                             {0,0,0}};

    std::vector<std::vector<int>> result  = {{0,0,0},
                                             {1,0,1},
                                             {0,1,1},
                                             {0,1,0}};
    
    gameOfLife(board);

    std::cout << "New board: "<< std::endl;
    for (int y = 0; y < m; ++y) {
        for (int x = 0; x < n; ++x) {
            std::cout << board[y][x] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <cstdlib>

template <typename T>
struct Node {
    public:
        T x;
        T y;
        Node* next;

    // Constructor
    Node(T x, T y) : x(x), y(y), next(nullptr) {};
};

template <typename T>
class Stack {
    public:
        Node<T>* head;

// Constructor
Stack() : head(nullptr) {};


    Node<T>* pop() {
        Node<T>* temp = head;
        head = head->next;
        return temp;
    }

    void push(Node<T>* node) {
        if (head == nullptr) {
            head = node;
        } else {
            node->next = head;
            head = node;
        }
    }

    Node<T>* peek() {
        return head;
    }

    bool linear_search(int x, int y) {
        Node<T>* current = head;
        while (current != nullptr) {
            if (x == current->x && y ==current->y){
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

class Maze {
    public:
        std::vector<std::vector<int>> maze;
        int end_x;
        int end_y;

        int size_x;
        int size_y;

    Maze(std::vector<std::vector<int>> maze, int end_x, int end_y) : end_x(end_x), end_y(end_y), maze(maze) {
        size_y = maze.size();
        size_x = maze[0].size();
    }

    int get_x_size() {
        return size_x;
    }

    int get_y_size() {
        return size_y;
    }

    int get_y_target() {
        return end_y;
    }

    int get_x_target() {
        return end_x;
    }

    std::vector<std::vector<int>> get_maze() {
        return maze;
    }
};

bool checkAtEnd(int x, int y, Maze maze) {
    int target_x = maze.get_x_target();
    int target_y = maze.get_y_target();

    if (x == target_x && y == target_y){
        return true;
    } else {
        return false;
    }
}

bool checkNeighbourOpen(Maze& maze, int new_x, int new_y) {
    /*
    We check if the neighbour given by (j, i) is open for our cell (y, x).
    The maze belongs to a grid on (m, n).
    */
    int m = maze.get_y_size();
    int n = maze.get_x_size();

    std::vector<std::vector<int>> maze_ = maze.get_maze();

    // Check if belongs to grid
    if ((new_y) < 0 || (new_y) >= m || (new_x) < 0 || (new_x) >= n) {
        return false;
    // Check if open
    } else if (maze_[new_y][new_x] == 1) {
        return true;
    } else {
        return false;
    }
}

bool inStack(Stack<int> stack, int x, int y){
    /*
    This will check if the (y,x) values are anywhere as a combo in the provided stack.
    */
    return stack.linear_search(x, y);
}

bool checkValidChoice(Maze maze, Stack<int> visited, int new_x, int new_y) {
    /*
    Checks if the given candidate new_x, new_y is valid.
    */
    
    // Checks if neighbour is open
    bool open_neighbour = checkNeighbourOpen(maze, new_x, new_y);

    // Check if we have visited it already
    bool have_visited = inStack(visited, new_x, new_y);

    return open_neighbour && !have_visited;
}

bool walkMaze(Maze maze, Stack<int> stack, Stack<int> visited, int x, int y) { /*
    We scan the 4 neighbours, and see if it is valid. If so, we take a step.

    If we either don't have valid next neighbours, or we have reached the target, we return.

    We return true if we found the end of the maze, false if we got stuck. If we get stuck, we 
    go to the next valid neighbour, or get stuck, which aain recursievelt returns to the previous 
    point.

    */

    bool result = false;

    // We check if we have found the end of the maze, if so we return true.
    bool at_end = checkAtEnd(x, y, maze);
    if (at_end) {
        std::cout << "Got to the end!\nReverse solution:" <<std::endl;
        return true;
    }

    // We are at this current node, we add it to the visited path.
    Node<int>* current_node = new Node<int>(x, y);
    visited.push(current_node);

    for (int i = -1; i<2; ++i){
        for (int j = -1; j<2; ++j){

            // This is the same cell, so we skip.
            if (i == 0 && j ==0) {
                continue;
            // This is a diagonal step, not valid.
            } else if (abs(i) + abs(j) == 2) {
                continue;
            }

            int new_x = x+i;
            int new_y = y+j;
            bool valid_neighbour = checkValidChoice(maze, visited, new_x, new_y);
            if (valid_neighbour) {

                stack.push(current_node);
                result = walkMaze(maze, stack, visited, new_x, new_y);

                // We found the end of the path, we skip all future work.
                if (result) {
                    std::cout << "(x, y) : " << new_x << " " << new_y << std::endl;
                    return result;
                }
            } 
        }
    }
    // If, for all options, we haven't found a valid path forward / the end, we pop the current node off of the stack,
    // and return false. This will bring us to the parent recursive call. It will also keep us from going back,
    // since the visited but dead-end node is added to visited.
    if (!result) {
        Node<int>* dead_end = stack.pop();
    }
    return result;
}


void MazeSolver(Maze maze, int& x, int& y) {

    Stack<int> stack;
    Stack<int> visited;

    bool found_end = walkMaze(maze, stack, visited, x, y);
}


int main() {

    std::vector<std::vector<int>> maze_ = {
        {0,1,0,0,0,0,0,0,0,0,0},
        {0,1,1,1,1,1,1,1,1,0,0},
        {0,0,0,0,1,0,0,0,0,0,0},
        {0,0,0,0,1,1,1,1,1,1,0},
        {0,0,0,0,0,0,0,0,0,1,0},
    };

    int target_x = 9;
    int target_y = 4;

    Maze* maze = new Maze(maze_, target_x, target_y);
    int start_x = 1;
    int start_y = 0;

    MazeSolver(*maze, start_x, start_y);

}

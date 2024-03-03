#include <iostream>
#include <vector>

template <typename T>
struct Node {
    public:
        T value;
        Node* left;
        Node* right;
        Node* parent;
    
    Node(T value) : value(value), left(nullptr), right(nullptr), parent(nullptr) {};

};


template <typename T>
bool search_function(Node<T>* node, T value) {

    bool result = false;
    // base case 1: we have reached an end of the tree
    if (node == nullptr){
        return false;
    }
    if (node->value == value) {
        return true;
    }
    result = search_function(node->left, value);
    if (result) {
        return true;
    }
    result = search_function(node->right, value);
    if (result) {
        return true;
    }
    return false;
}


template <typename T>
void preorder_traversal(Node<T>* node) {
    // base case 1: we have reached an end of the tree
    if (node == nullptr){
        //std::cout << "empty node reached" << std::endl;
        return;
    }
    std::cout << node->value << std::endl;
    preorder_traversal(node->left);
    preorder_traversal(node->right);
}

template <typename T>
class Tree {
    public:
        T root;

    Tree() : root(nullptr) {};
    Tree(T root) : root(root) {};


    // Insert root
    void insertRoot(T root_entry) {
        std::cout << "Inserted "<< root_entry->value << " as root." << std::endl;
        root = root_entry;
    }

    // Insert a new node into the tree
    void insert(T new_node) {
        /*
        This method is not guarantted to correctly place the node: to do we need to feed in the data
        from top to bottom of the tree in the correct order.
        */
        T current = root;
        bool inserted = false;

        while (!inserted) {
            // Base case 1: if the tree has not been populated beyond current, we add a new node.
            if (current->left == nullptr && new_node->value <= current->value) {
                current->left = new_node;
                new_node->parent = current;
                inserted = true;
                std::cout << "Inserted "<< new_node->value << " to the left of " << current->value << std::endl;
                return;
            } else if (current->right == nullptr && new_node->value > current->value) {
                current->right = new_node;
                new_node->parent = current;
                inserted = true;
                std::cout << "Inserted "<< new_node->value << " to the right of " << current->value << std::endl;
                return;
            } 
            // Base case 2: if the tree has been populated, we keep navigating the tree
            else if (new_node->value <= current->value){
                current = current->left; 
            } else if (new_node->value > current->value){
                current = current->right;
            }
        }
    }

    void traversal() {
        std::cout << "\nTraversing the tree:" << std::endl;
        preorder_traversal(root); 
    }

    bool search(int value) {
        bool result = search_function(root, value);
        return result;
    }
};


void populateTree(Tree<Node<int>*> &tree, std::vector<int> &vec, int low, int high){
    /*
    Takes in a sorted vector, and populates the tree so that it is a Binary Search Tree
    */

    // Base case 1: low==high, we can't recurse anymore, we exit. 
    // We have already covered this entry with low==median.
    int median_index = low+(high-low)/2;
    if ((low == high) && (low == median_index)) {
        return;
    }
    // Base case 2: low == median. We enter the value and exit, no recursion.
    // Need to be SUPER careful with these 1-off errors in the median.
    if (low >= median_index) {
        Node<int>* node = new Node<int>(vec[median_index]);
        tree.insert(node);
        return;
    }

    // Base case 3: Tree is empty. We initialise tree with root and do recursion.
    if (low == 0 && high == vec.size()) {
        Node<int>* root = new Node<int>(vec[median_index]);
        tree.insertRoot(root);
    } 
    // Base case 4: the tree has been initialised and we cna still do recursion. 
    // We add elements and do recursion.
    else {
        Node<int>* node = new Node<int>(vec[median_index]);
        tree.insert(node);
    }

    populateTree(tree, vec, low, median_index);
    populateTree(tree, vec, median_index+1, high);

}

template <typename T>
void displayVec(std::vector<T> vec) {
    std::cout << "\nPrinting the vector: \n";
    for (int i = 0; i< vec.size(); ++i){
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}


template <typename T>
void quickSort(std::vector<T> &vec, int low, int high) {
    
    // Base case 1: only one element left
    if (low >= high) {
        return;
    }

    int pivot_index = low;
    T pivot = vec[high];
    for (int i = low; i < high; ++i) {
        if (vec[i] < pivot) {
            T temp = vec[i];
            vec[i] =  vec[pivot_index];
            vec[pivot_index] = temp;
            ++pivot_index;
        }
    }

    // Swap pivot
    T temp = vec[pivot_index];
    vec[pivot_index] = pivot;
    vec[high] = temp;

    // Call recursion
    quickSort(vec, low, pivot_index-1);
    quickSort(vec, pivot_index+1, high);
}

int main() {


    // Sort a vec
    int size = 10;
    std::vector<int> vec;
    for (int i = 0; i < size; ++i) {
        if (i%2 == 0){
            vec.push_back(i*3);
        } else {
            vec.push_back(i);
        }
    }
    
    displayVec(vec);

    // Sort the vector
    std::cout << "\nSorting the vector" << std::endl;
    quickSort(vec, 0, size-1);

    displayVec(vec);

    // Insert values into the tree
    Tree<Node<int>*> tree;
    populateTree(tree, vec, 0, size);

    tree.traversal();


    // Binary Search
    std::cout << "\nSearching the tree" << std::endl;
    int value = 11;
    bool result = tree.search(value);
    if (result) {
        std::cout << "Found the value " << value << std::endl;
    } else {
        std::cout << "Did not find the value " << value << std::endl;
    }

    return 0;
}
#include <iostream>
#include <vector>

template <typename T>
struct Node {
    public:
        T value;
        Node* next;

    Node(T value) : value(value), next(nullptr) {};

};


template <typename T>
class Queue {
    public:
        Node<T>* head;
        Node<T>* tail;
        int size;
    
    Queue() : head(nullptr), tail(nullptr), size(0) {};

    void queue(T value) {
        Node<T>* new_tail = new Node<T>(value);
        if (tail == nullptr) {
            head = tail = new_tail;
        } else {
            tail->next = new_tail;
            tail = new_tail;
        }
        size +=1;
    }

    Node<T>* deque() {

        if (size == 0) {
            std::cout << "Queue is empty" << std::endl;
            return new Node<T>(0);
        }

        Node<T>* temp = head; //  we will pop this off.
        head = head->next;
        if (size == 1) {
            --size;
            head = nullptr;
            tail = nullptr;
            return temp; // Memory leak of temp? I think not, it only exists in this scope.
        } else {
            --size;
            return temp;
        }
    }

    void display() {
        Node<T>* current = head;
        std::cout << "Printing the queue:" << std::endl;
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};



template <typename T>
struct TreeNode {
        public:
                T value;
                TreeNode* parent;
                std::vector<TreeNode*> children;

        // Constructor
        TreeNode(T value) : value(value), parent(nullptr), children() {};
        TreeNode(T value, TreeNode* parent) : value(value), parent(parent), children() {};
};

template <typename T>
class Tree {
        public:
            TreeNode<T>* root;

        // Constructor
        Tree() : root(nullptr) {};
        Tree(TreeNode<T>* root) : root(root) {};

        void insert_root(TreeNode<T>* node){
            root = node;
        }

        void insert(TreeNode<T>* parent, TreeNode<T>* node) {
            parent->children.push_back(node);
        }
};


template <typename T>
bool preorder_traversal(TreeNode<T>* parent) {
        /*
        We print out eahc node as we get to it, before we call recursion.
        There is no search, we stop each recursion once we get to a node with no children.
        */

        std::cout << "TreeNode " << parent->value << std::endl;

        // Base case: this node has no children, so we return false.
        if (parent->children.size() == 0) {
                return false;
        }
       
        // No base cases met, we call recursively on children
        for (auto child : parent->children) {
                bool result = preorder_traversal(child);
        }

        // We've traversed this part of the tree.
        return false;
}

template <typename T>
bool BFS(TreeNode<T>* parent, Queue<TreeNode<T>*> queue, T value) {

    // Base case 1: we've found the value, so we return true
    if (parent->value == value) {
        std::cout << "\nWe found the value! Reverse path: " << std::endl;
        return true;
    }

    // Add all children to queue.
    for (int i = 0; i < parent->children.size(); ++i) {
        TreeNode<T>* child = parent->children[i]; 
        queue.queue(child); // We're putting the entire node into there... interesting. A ver.
    }

    // We deque the next queue element, and call the recursion.
    TreeNode<T>* current = queue.deque()->value;
    bool result = BFS(current, queue, value);
    if (result) {
        std::cout << current->value << std::endl;
    }
    // if false: base case 2: we've still not found the value, it doesn't exist. 
    // if true: base case 1: we found the value, we propagate it back.
    return result;

}


int main() {

    // Testing Queue
    Queue<int> myQueue;

    for (int i = 0; i < 5; ++i) {
        myQueue.queue(i);
    }
    myQueue.display();
    

    Node<int>* popped = myQueue.deque();
    std::cout << "Popped: " << popped->value << std::endl;
    //int popped;
    //for (int i = 0; i < 6; ++i) {
        //popped = myQueue.deque();
    //}
    
    myQueue.display();
    // Testing Queue done



    // Building tree
    TreeNode<int>* root = new TreeNode<int>(0);
    Tree<int> tree;
    tree.insert_root(root); 
    
    // Creates nodes 
    TreeNode<int>* node1 = new TreeNode(1);
    TreeNode<int>* node2 = new TreeNode(2);
    TreeNode<int>* node3 = new TreeNode(3);
    tree.insert(root, node1);
    tree.insert(root, node2);
    tree.insert(root, node3);

    TreeNode<int>* node4 = new TreeNode(4);
    TreeNode<int>* node5 = new TreeNode(5);
    tree.insert(node2, node4);
    tree.insert(node2, node5);

    // Traverse tree
    std::cout << "\nPre-order traversal" << std::endl;
    bool result = preorder_traversal(root);

    // Breadth-First Search
    Queue<TreeNode<int>*> BFS_queue;
    int target = 5;
    std::cout << "\nBreadth First Search, for target: " << target << std::endl;
    bool found_val = BFS(root, BFS_queue, target);

    return 0;
}

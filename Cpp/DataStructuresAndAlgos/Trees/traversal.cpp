#include <iostream>
#include <vector>

template <typename T>
struct Node {
        public:
                T value;
                Node* parent;
                std::vector<Node*> children;

        // Constructor
        Node(T value) : value(value), parent(nullptr), children() {};
        Node(T value, Node* parent) : value(value), parent(parent), children() {};
};

template <typename T>
class Tree {
        public:
                Node<T>* root;

        // Constructor
        Tree() : root(nullptr) {};
        Tree(Node<T>* root) : root(root) {};

        void insert_root(Node<T>* node){
                root = node;
        }

        void insert(Node<T>* parent, Node<T>* node) {
              parent->children.push_back(node);
        }
};

template <typename T>
bool traverse_tree(Node<T>* parent, T value) {
        // Base case 1: we found the value we want
        if (parent->value == value) {
                std::cout << "We found the node!" << std::endl;
                std::cout << "Reverse path: " << std::endl;
                return true;
        }
        // Base case 2: this node has no children, so we return false.
        if (parent->children.size() == 0) {
                std::cout << "Value "<< value << " is not a child of " << parent->value << std::endl;
                return false;
        }
       
        // No base cases met, we call recursively on children
        for (auto child : parent->children) {
                bool result = traverse_tree(child, value);
                if (result){
                        std::cout << child->value << std::endl;
                        return result;
                }
        }

        // We've never found anything in this part of the tree that matches the value.
        std::cout << "Value "<< value << " is not a child of " << parent->value << std::endl;
        return false;
}

int main() {

        Node<int>* root = new Node<int>(0);
        Tree<int> tree;
        tree.insert_root(root); 
        
       // Creates nodes 
        Node<int>* node1 = new Node(1);
        Node<int>* node2 = new Node(2);
        Node<int>* node3 = new Node(3);
        tree.insert(root, node1);
        tree.insert(root, node2);
        tree.insert(root, node3);

        Node<int>* node4 = new Node(4);
        Node<int>* node5 = new Node(5);
        tree.insert(node2, node4);
        tree.insert(node2, node5);
        bool result = traverse_tree(root, 5);

}


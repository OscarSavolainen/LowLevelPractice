#include <iostream>
#include <vector>


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
bool compare_trees(TreeNode<T>* parent1, TreeNode<T>* parent2) {
    // Base case 1: the nb of children for this node are not the same across the two trees
    if (parent1->children.size() != parent2->children.size() ) {
        std::cout << "Oh no!" << std::endl;
        return false;
    }

    // Base case 2: the values of the nodes aren't equal.
    if (parent1->value != parent2->value) {
        return false;
    }

    // If the two trees have the same number of children and their values are equal, 
    // we call the function recursively on the chldren pairs
    for (int i = 0; i< parent1->children.size(); ++i){
        TreeNode<T>* child1 = parent1->children[i];
        TreeNode<T>* child2 = parent2->children[i];
        bool result = compare_trees(child1, child2);
        if (!result) {
            return result;
        }
    }

    // Base case 3: none of the recursive calls have found a mismatch.
    return true;

}

int main() {

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


    // Compare Trees
    std::cout << "\nTesting if matched trees are matched:" << std::endl;
    bool matched = compare_trees(root, root);
    if (matched) {
        std::cout << "The trees are matched!" << std::endl;
    } else {
        std::cout << "The trees are NOT matched!" << std::endl;
    }

    std::cout << "\nTesting if unmatched trees are matched:" << std::endl;
    matched = compare_trees(root, root->children[0]);
    if (matched) {
        std::cout << "The trees are matched!" << std::endl;
    } else {
        std::cout << "The trees are NOT matched!" << std::endl;
    }

    return 0;
}

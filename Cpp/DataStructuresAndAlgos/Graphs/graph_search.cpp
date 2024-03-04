#include <iostream>
#include <vector>
#include <unordered_map>

template <typename T>
struct Node {
    public:
        T value;
        Node* next;

    // Constructor
    Node(T value) : value(value), next(nullptr) {}
};


template <typename T>
class Stack {
    public: 
        Node<T>* head;

    Stack() : head(nullptr) {};

    void push(T value) {
        Node<T>* node = new Node<T>(value);
        if (head == nullptr) {
            head = node;
        } else {
            node->next = head;
            head = node;
        } 
        return;
    }

    T pop() {
        Node<T>* new_head = head->next;
        T value = head->value;
        delete head;
        head = new_head;
        return value;
    }
};


template <typename T>
class Graph {
    private:
        std::unordered_map<T, std::vector<T>> adj_list;

    public:
        void addEdge(T a, T b) {
            adj_list[a].push_back(b);
        }

        std::vector<T> getNexts(T a) {
            return adj_list[a];
        }

        void printGraph() {
            std::cout << "Printing the graph: " << std::endl;
            for (auto& v : adj_list) {
                std::cout << v.first << " : ";
                for (int i = 0; i< v.second.size(); ++i) {
                    std::cout << v.second[i] << " ";
                }
                std::cout << std::endl;
            }
        }

        bool findPath(T a, T b){
            // Base case 1: we have reached the desired node
            if (a == b) {

                std::cout << "\nReverse path: \n" << a << std::endl;
                return true;
            }

            std::vector<T> nexts = adj_list[a];

            // Base case 2: the current node doesn't have next nodes, we return.
            if (nexts.size() == 0) {
                return false;
            }

            // We haven't reached the desired node or an end: we recurse
            bool result = false;
            for (int i = 0; i< nexts.size(); ++i) {
                result = findPath(nexts[i], b);
                if (result) {
                    std::cout << a << std::endl;
                    return result;
                }
            }
            return result;
        }
};



int main() {

    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 1);
    g.addEdge(5, 3);
    g.addEdge(3, 4);

    g.printGraph();


    g.findPath(0, 4);
               
    //Stack myStack;
    //myStack.push


    return 0;
}
#include <iostream>
#include <tuple>
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
class Queue {
    private:
        Node<T>* head;
        Node<T>* tail;
        int length;

    public:

        Queue() : head(nullptr), tail(nullptr), length(0) {};

        int getLength() {
            return length;
        }

        void queue(T value) {
            Node<T>* new_tail = new Node<T>(value);
            if (tail == nullptr){
                tail = head = new_tail;
            } else {
                tail->next = new_tail;
                tail = new_tail;
            }
            length += 1;
        }

        T deque() {
            if (head == nullptr) {
                std::cout << "Queue is already empty" << std::endl;
                T a;
                return a;
            }
            if (head == tail){
                T value = head->value;
                head = nullptr;
                tail = nullptr;
                delete head;
                delete tail;
                length -= 1;
                return value;
            }

            Node<T>* new_head = head->next;
            T value = head->value;
            delete head;
            head = new_head;
            length -= 1;
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

        void findShortestPath(T a, T b){
            /* 
            We use an iterative algorithim (BFS) to find the shortest path. 
            */

            Queue<std::tuple <T, int>> queue;
            T current = a;
            std::tuple <T, int> mytuple = std::make_tuple(current, 0);
            queue.queue(mytuple);
            int distance = 0;


            while (queue.getLength() > 0) {
                std::tuple <T, int> current_tuple = queue.deque();
                current = std::get<0>(current_tuple);
                distance = std::get<1>(current_tuple);

                if (current == b) {
                    std::cout << "Shortest path between " << a << " and " << b << " is "  << distance << std::endl;
                    return;
                }

                std::vector<T> nexts = adj_list[current];
                for (int i = 0; i < nexts.size(); ++i)
                {
                    T next = nexts[i];
                    std::tuple <T, int> mytuple = std::make_tuple(next, distance+1);
                    queue.queue(mytuple);
                }
            }

            std::cout << "The path between " << a << " and " << b << " does not exist" << std::endl;
            return;

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
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(5, 7);

    g.printGraph();


    g.findShortestPath(0, 7);
               
    //Stack myStack;
    //myStack.push


    return 0;
}
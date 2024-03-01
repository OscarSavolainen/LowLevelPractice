#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;

    // Constructor
    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class Queue {
    private:
        Node<T>* head;
        Node<T>* tail;

    public:

        // Constructor
        Queue() : head(nullptr), tail(nullptr) {}

        // Deconstructor
        ~Queue() {
            while (head != nullptr) {
                Node<T>* temp = head;
                head =  head->next;
                delete temp;
            }
        }

        
        T pop() {
            Node<T>* temp = tail;
            T value = tail->data;
            if (tail != head) {
                tail = tail->prev;
                delete temp;
            } else {
                tail = nullptr;
                head = nullptr;
                delete temp;
            } 
            return value;
        }

        void push(T value) {
            Node<T>* new_head = new Node<T>(value);
            if (head == nullptr) {
                head = tail = new_head;
            } else {
                new_head->next = head;
                head->prev = new_head;
                head = new_head;
            }
        }

        T peek() {
            if (head == nullptr) {
                std::cout << "List is empty, returning 0" << std::endl;
                return 0;
            }
            return head->data;
        }

};


int main() {

    Queue<int> myQueue;
    myQueue.push(10);
    myQueue.push(1333);
    myQueue.push(14);
    std::cout << "Peek: " << myQueue.peek() << std::endl;
    myQueue.push(15);
    std::cout << "Peek: " << myQueue.peek() << std::endl;

    std::cout << "Popped: " << myQueue.pop() << std::endl;
    std::cout << "Popped: " << myQueue.pop() << std::endl;
    std::cout << "Popped: " << myQueue.pop() << std::endl;
    std::cout << "Popped: " << myQueue.pop() << std::endl;


    std::cout << "Peek: " << myQueue.peek() << std::endl;

    myQueue.push(14);
    std::cout << "Peek: " << myQueue.peek() << std::endl;
    myQueue.push(15);
    std::cout << "Peek: " << myQueue.peek() << std::endl;

    std::cout << "Popped: " << myQueue.pop() << std::endl;
    std::cout << "Popped: " << myQueue.pop() << std::endl;

    return 0;
}

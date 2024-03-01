#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {};
};

template <typename T>
class Stack {
    private:
        Node<T>* head;

    public:
        // Constructor
        Stack() : head(nullptr) {};

        // Deconstructor
        ~Stack() {
            while (head != nullptr) {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
            }
        }

        void push(T value) {
            Node<T>* new_head = new Node<T>(value);
            new_head->next = head;
            head = new_head;
        }

        T pop() {
            if (head == nullptr) {
                std::cout << "Stack is empty" << std::endl;
                return -1;
            }
            T value = head->data;
            Node<T>* next_head = head->next;
            delete head;
            head = next_head;
            return value;
        }

        T peep() {
            if (head != nullptr) {
                return head->data;
            } else {
                std::cout << "Stack empty" << std::endl;
                return -1;
            }
        }

};

int main() {

    Stack<int> myStack;
    myStack.push(10);
    std::cout << myStack.peep() << std::endl;
    myStack.push(20);
    std::cout << myStack.peep() << std::endl;
    myStack.push(100);
    std::cout << myStack.peep() << std::endl;


    std::cout << "Pop: " << myStack.pop() << std::endl;
    std::cout << "Pop: " << myStack.pop() << std::endl;
    std::cout << "Pop: " << myStack.pop() << std::endl;
    std::cout << "Pop: " << myStack.pop() << std::endl;

    myStack.push(10);
    std::cout << myStack.peep() << std::endl;
    return 0;
}
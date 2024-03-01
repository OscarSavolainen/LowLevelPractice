#include <iostream>

template <typename T>
struct Node {
    T value;
    Node* next;
    Node* prev;

    Node(T data) : value(data), next(nullptr), prev(nullptr) {}
};

template <typename T>
class LinkedList {
    private:
        Node<T>* head;
        Node<T>* tail;

    public:

        // Constructor
        LinkedList() : head(nullptr), tail(nullptr) {}

        // Deconstructor
        ~LinkedList() {
            while (head != tail) {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
            }
            if (head == tail) {
                delete head;
            }
        }

        // Constant time head/tail operations
        T getHeadVal () {
            return head->value;
        }

        T getTailVal () {
            return tail->value;
        }

        void pushFront(T value) {
            Node<T>* new_node = new Node<T>(value);
            if (head == nullptr) {
                head = tail = new_node;
            } else {
                new_node->next = head;
                head->prev = new_node;
                head = new_node;
            }
        }
        
        void pushBack(T value) {
            Node<T>* new_node = new Node<T>(value);
            if (head == nullptr) {
                head = tail = new_node;
            } else {
                new_node->prev = tail;
                tail->next = new_node;
                tail = new_node;
            }
        }

        T popFront() {
            T value = head->value;
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            head->prev = nullptr; // Maybe?
            return value;
        }

        T popBack() {
            T value = tail->value;
            Node<T>* temp = tail;
            tail = tail->prev;
            delete temp;
            tail->next = nullptr; // Maybe?
            return value;
        }

        // Linear Search
        int linearSearchForVal(T value) {
            int index = 0;
            Node<T>* node = head;
            while (node != nullptr) {
                if (value == node->value) {
                    return index;
                }
                node = node->next;
                index +=1;
            }
            

            // The value is not in the list.
            std::cout << "The value " << value << " is not in the list" << std::endl;
            return -1;
        } 

        // Display
        void display() {
            Node<T>* current = head;
            std::cout << "Our linked list: \n";
            while (current != nullptr) {
                std::cout << current->value << " ";
                current = current->next;
            }
            std::cout << std::endl;
            //if (current == tail) {
                //std::cout << current->value << std::endl;
            //}
        }
};

int main() {

    LinkedList<int> myList;

    myList.pushFront(10);
    myList.pushFront(20);
    myList.pushFront(100);

    std::cout << "Tail val: " << myList.getTailVal() << "\n";
    myList.pushBack(1000);
    std::cout << "New tail val: " << myList.getTailVal() << "\n";

    myList.display();

    int index = myList.linearSearchForVal(1000);
    std::cout << "Index of 1000 is " << index << std::endl;

    std::cout << "Popped tail: " << myList.popBack() << std::endl;

    myList.display();

    index = myList.linearSearchForVal(1000);
    std::cout << "Index of 1000 is " << index << std::endl;


    std::cout << "Popped head: " << myList.popFront() << std::endl;
    myList.display();

    return 0;
}
#include <iostream>
using namespace std;

// Define a linked list node
struct Node {
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

class MyLinkedList {

private:
    Node* head;
    int length;

public:

    // Constructor
    MyLinkedList() {
        head = NULL;
        length = 0;
    }

    // Get value at a particular index
    int get(int index) {

        if (index < 0 || index >= length) {
            return -1;
        }

        Node* current = head;

        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        return current->val;
    }

    // Add node at the beginning
    void addAtHead(int val) {

        Node* newNode = new Node(val);

        newNode->next = head;
        head = newNode;

        length++;
    }

    // Add node at the end
    void addAtTail(int val) {

        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
        }
        else {

            Node* current = head;

            while (current->next != NULL) {
                current = current->next;
            }

            current->next = newNode;
        }

        length++;
    }

    // Add node at a particular index
    void addAtIndex(int index, int val) {

        if (index < 0 || index > length) {
            return;
        }

        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* current = head;

        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }

        Node* newNode = new Node(val);

        newNode->next = current->next;
        current->next = newNode;

        length++;
    }

    // Delete node at a particular index
    void deleteAtIndex(int index) {

        if (index < 0 || index >= length) {
            return;
        }

        Node* temp;

        if (index == 0) {

            temp = head;
            head = head->next;

            delete temp;
        }
        else {

            Node* current = head;

            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }

            temp = current->next;
            current->next = temp->next;

            delete temp;
        }

        length--;
    }

    // Display the linked list
    void display() {

        Node* current = head;

        while (current != NULL) {
            cout << current->val << " -> ";
            current = current->next;
        }

        cout << "NULL" << endl;
    }

    // Destructor: free allocated memory
    ~MyLinkedList() {

        Node* current = head;

        while (current != NULL) {

            Node* temp = current;
            current = current->next;

            delete temp;
        }
    }
};

int main() {

    MyLinkedList myLinkedList;

    // Add elements
    myLinkedList.addAtHead(1);
    myLinkedList.addAtTail(3);
    myLinkedList.addAtIndex(1, 2);

    cout << "Linked List: ";
    myLinkedList.display();

    // Get value at index 1
    cout << "Value at index 1: ";
    cout << myLinkedList.get(1) << endl;

    // Delete node at index 1
    myLinkedList.deleteAtIndex(1);

    cout << "After deletion: ";
    myLinkedList.display();

    // Get value again
    cout << "Value at index 1: ";
    cout << myLinkedList.get(1) << endl;

    return 0;
}


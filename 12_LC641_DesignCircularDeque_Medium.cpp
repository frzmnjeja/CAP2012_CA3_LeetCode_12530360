#include <iostream>
using namespace std;

class MyCircularDeque {

private:
    int* arr;
    int capacity;
    int front;
    int rear;
    int count;

public:

    // Constructor
    MyCircularDeque(int k) {

        capacity = k;
        arr = new int[capacity];

        front = 0;
        rear = -1;
        count = 0;
    }

    // Insert element at the front
    bool insertFront(int value) {

        if (isFull()) {
            return false;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
        }
        else {
            front = (front - 1 + capacity) % capacity;
        }

        arr[front] = value;
        count++;

        return true;
    }

    // Insert element at the rear
    bool insertLast(int value) {

        if (isFull()) {
            return false;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
        }
        else {
            rear = (rear + 1) % capacity;
        }

        arr[rear] = value;
        count++;

        return true;
    }

    // Delete element from the front
    bool deleteFront() {

        if (isEmpty()) {
            return false;
        }

        if (count == 1) {
            front = 0;
            rear = -1;
        }
        else {
            front = (front + 1) % capacity;
        }

        count--;

        return true;
    }

    // Delete element from the rear
    bool deleteLast() {

        if (isEmpty()) {
            return false;
        }

        if (count == 1) {
            front = 0;
            rear = -1;
        }
        else {
            rear = (rear - 1 + capacity) % capacity;
        }

        count--;

        return true;
    }

    // Get front element
    int getFront() {

        if (isEmpty()) {
            return -1;
        }

        return arr[front];
    }

    // Get rear element
    int getRear() {

        if (isEmpty()) {
            return -1;
        }

        return arr[rear];
    }

    // Check whether deque is empty
    bool isEmpty() {

        return count == 0;
    }

    // Check whether deque is full
    bool isFull() {

        return count == capacity;
    }

    // Destructor
    ~MyCircularDeque() {

        delete[] arr;
    }
};

int main() {

    MyCircularDeque deque(3);

    cout << "Insert Last 1: ";
    cout << deque.insertLast(1) << endl;

    cout << "Insert Last 2: ";
    cout << deque.insertLast(2) << endl;

    cout << "Insert Front 3: ";
    cout << deque.insertFront(3) << endl;

    cout << "Insert Front 4: ";
    cout << deque.insertFront(4) << endl;

    cout << "Rear Element: ";
    cout << deque.getRear() << endl;

    cout << "Is Full: ";
    cout << deque.isFull() << endl;

    cout << "Delete Last: ";
    cout << deque.deleteLast() << endl;

    cout << "Insert Front 4: ";
    cout << deque.insertFront(4) << endl;

    cout << "Front Element: ";
    cout << deque.getFront() << endl;

    return 0;
}


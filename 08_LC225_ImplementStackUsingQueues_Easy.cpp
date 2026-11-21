#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q1;
    queue<int> q2;

public:
    // Push element onto the stack
    void push(int x) {
        q2.push(x);

        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap the queues
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    // Remove and return the top element
    int pop() {
        int value = q1.front();
        q1.pop();
        return value;
    }

    // Return the top element
    int top() {
        return q1.front();
    }

    // Check whether the stack is empty
    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack myStack;

    myStack.push(1);
    myStack.push(2);

    cout << "Top element: " << myStack.top() << endl;

    cout << "Popped element: " << myStack.pop() << endl;

    cout << "Is stack empty? ";
    if (myStack.empty()) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}


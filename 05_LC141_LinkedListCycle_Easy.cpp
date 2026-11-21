#include <iostream>
using namespace std;

// Define Linked List Node
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    bool hasCycle(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};

int main() {

    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    ListNode* head = NULL;
    ListNode* tail = NULL;

    ListNode* nodes[10000];

    cout << "Enter linked list elements: ";

    for (int i = 0; i < n; i++) {

        int value;
        cin >> value;

        ListNode* newNode = new ListNode(value);
        nodes[i] = newNode;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int pos;

    cout << "Enter cycle position (-1 for no cycle): ";
    cin >> pos;

    if (pos >= 0 && pos < n) {
        tail->next = nodes[pos];
    }

    Solution obj;

    bool result = obj.hasCycle(head);

    if (result) {
        cout << "Cycle detected: true" << endl;
    }
    else {
        cout << "Cycle detected: false" << endl;
    }

    // Break cycle before deleting nodes
    if (tail != NULL) {
        tail->next = NULL;
    }

    ListNode* temp = head;

    while (temp != NULL) {
        ListNode* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return 0;
}


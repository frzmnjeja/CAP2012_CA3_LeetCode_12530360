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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both until fast reaches the end
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete the nth node
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;

        delete toDelete;

        ListNode* newHead = dummy->next;

        delete dummy;

        return newHead;
    }
};

int main() {

    int size;

    cout << "Enter number of nodes: ";
    cin >> size;

    ListNode* head = NULL;
    ListNode* tail = NULL;

    cout << "Enter linked list elements: ";

    for (int i = 0; i < size; i++) {

        int value;
        cin >> value;

        ListNode* newNode = new ListNode(value);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int n;

    cout << "Enter N (position from end): ";
    cin >> n;

    Solution obj;

    head = obj.removeNthFromEnd(head, n);

    cout << "Updated Linked List: ";

    ListNode* temp = head;

    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << endl;

    // Free remaining memory
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}


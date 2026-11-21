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
    ListNode* removeElements(ListNode* head, int val) {

        // Remove matching nodes from the beginning
        while (head != NULL && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        // Remove matching nodes from the remaining list
        ListNode* current = head;

        while (current != NULL && current->next != NULL) {

            if (current->next->val == val) {

                ListNode* temp = current->next;
                current->next = current->next->next;

                delete temp;
            }
            else {
                current = current->next;
            }
        }

        return head;
    }
};

int main() {

    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    ListNode* head = NULL;
    ListNode* tail = NULL;

    cout << "Enter linked list elements: ";

    for (int i = 0; i < n; i++) {

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

    int val;

    cout << "Enter value to remove: ";
    cin >> val;

    Solution obj;

    head = obj.removeElements(head, val);

    cout << "Updated Linked List: ";

    ListNode* current = head;

    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
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


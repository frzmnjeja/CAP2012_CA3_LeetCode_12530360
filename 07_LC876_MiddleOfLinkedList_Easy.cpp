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
    ListNode* middleNode(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
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

    Solution obj;

    ListNode* middle = obj.middleNode(head);

    cout << "Middle Linked List: ";

    while (middle != NULL) {
        cout << middle->val << " ";
        middle = middle->next;
    }

    cout << endl;

    // Free allocated memory
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}


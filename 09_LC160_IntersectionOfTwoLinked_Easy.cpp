#include <iostream>
using namespace std;

// Define linked list node
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

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        ListNode* pA = headA;
        ListNode* pB = headB;

        while (pA != pB) {

            if (pA == NULL) {
                pA = headB;
            }
            else {
                pA = pA->next;
            }

            if (pB == NULL) {
                pB = headA;
            }
            else {
                pB = pB->next;
            }
        }

        return pA;
    }
};

int main() {

    // Create shared nodes
    ListNode* common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);

    // Create List A: 4 -> 1 -> 8 -> 4 -> 5
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    // Create List B: 5 -> 6 -> 1 -> 8 -> 4 -> 5
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    // Find intersection
    Solution obj;

    ListNode* result = obj.getIntersectionNode(headA, headB);

    // Display result
    if (result != NULL) {
        cout << "Intersected at: " << result->val << endl;
    }
    else {
        cout << "No intersection" << endl;
    }

    // Free List A's unique nodes
    ListNode* temp = headA;

    while (temp != common) {
        ListNode* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    // Free List B's unique nodes
    temp = headB;

    while (temp != common) {
        ListNode* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    // Free shared nodes once
    temp = common;

    while (temp != NULL) {
        ListNode* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return 0;
}


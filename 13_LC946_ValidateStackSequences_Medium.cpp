#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:

    bool validateStackSequences(vector<int>& pushed,
                                vector<int>& popped) {

        stack<int> st;

        int j = 0;

        for (int i = 0; i < pushed.size(); i++) {

            // Push element into stack
            st.push(pushed[i]);

            // Check whether stack top matches popped element
            while (!st.empty() && st.top() == popped[j]) {

                st.pop();
                j++;
            }
        }

        // If all elements were popped, sequence is valid
        return j == popped.size();
    }
};

int main() {

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> pushed(n);
    vector<int> popped(n);

    cout << "Enter pushed sequence: ";

    for (int i = 0; i < n; i++) {
        cin >> pushed[i];
    }

    cout << "Enter popped sequence: ";

    for (int i = 0; i < n; i++) {
        cin >> popped[i];
    }

    Solution obj;

    bool result = obj.validateStackSequences(pushed, popped);

    if (result) {
        cout << "Valid Stack Sequence: true" << endl;
    }
    else {
        cout << "Valid Stack Sequence: false" << endl;
    }

    return 0;
}


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int j = 0;

        // Move all non-zero elements to the front
        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            }
        }

        // Fill the remaining positions with zeroes
        while (j < nums.size()) {
            nums[j] = 0;
            j++;
        }
    }
};

int main() {

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    obj.moveZeroes(nums);

    cout << "Array after moving zeroes: ";

    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    cout << endl;

    return 0;
}


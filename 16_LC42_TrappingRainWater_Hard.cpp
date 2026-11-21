#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;

    int leftMax = 0;
    int rightMax = 0;
    int water = 0;

    while (left < right) {

        if (height[left] < height[right]) {

            if (height[left] >= leftMax) {
                leftMax = height[left];
            }
            else {
                water += leftMax - height[left];
            }

            left++;
        }
        else {

            if (height[right] >= rightMax) {
                rightMax = height[right];
            }
            else {
                water += rightMax - height[right];
            }

            right--;
        }
    }

    return water;
}

int main() {

    vector<int> height(12);

	height[0] = 0;
	height[1] = 1;
	height[2] = 0;
	height[3] = 2;
	height[4] = 1;
	height[5] = 0;
	height[6] = 1;
	height[7] = 3;
	height[8] = 2;
	height[9] = 1;
	height[10] = 2;
	height[11] = 1;
    int result = trap(height);

    cout << "Trapped Rain Water: " << result << endl;

    return 0;
}


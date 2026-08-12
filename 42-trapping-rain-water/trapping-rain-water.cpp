class Solution {
public:
    int trap(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;

        int leftMax = 0;
        int rightMax = 0;

        int wtr = 0;

        while (left < right) {

            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);

            if (leftMax < rightMax) {

                wtr += leftMax - height[left];
                left++;

            } else {

                wtr += rightMax - height[right];
                right--;
            }
        }

        return wtr;
    }
};
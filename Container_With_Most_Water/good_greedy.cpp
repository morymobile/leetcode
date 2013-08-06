class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxArea = 0;
        int i = 0, j = height.size() -1;
        while (i < j) {
            const int area = (j-i) * min(height[i], height[j]);
            if (maxArea < area)
                maxArea = area;
            if (height[i] < height[j])
                ++i;
            else
                --j;
        }
        return maxArea;
    }
};

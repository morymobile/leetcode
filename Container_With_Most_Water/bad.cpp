class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxArea = 0;
        int size = height.size();
        for (int i = 0; i < size; ++i) {
            for (int j = i+1; j < size; ++j) {
                const int area = (j-i) * min(height[i], height[j]);
                if (maxArea < area)
                    maxArea = area;
            }
        }
        return maxArea;
    }
};

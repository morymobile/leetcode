class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int y = (x > 0) ? x : -x;
        int ret = 0;
        while (y != 0) {
            ret = (ret * 10) + (y % 10);
            y /= 10;
        };
        
        return (x > 0) ? ret : -ret;
    }
};

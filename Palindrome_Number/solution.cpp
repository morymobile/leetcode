class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x < 0)
            return false;

        long long ret = 0, y = x;
        while (y) {
            ret = ret * 10 + (y % 10);
            y /= 10;
        };
        return ret == x;
    }
};

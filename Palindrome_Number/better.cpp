class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x < 0)
            return false;

        int divide = 1, y = x;
        while (y >= 10) {
            divide *= 10;
            y /=10;
        }
        
        int multiply = 1;
        y = x;
        while (true) {
            if ((y/divide)%10 != (y/multiply)%10)
                return false;
            if (divide == multiply || divide == multiply * 10)
                return true;
            divide /= 10;
            multiply *= 10;
        };
    }
};

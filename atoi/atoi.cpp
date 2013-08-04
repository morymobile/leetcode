class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (str == NULL || *str == '\0')
            return 0;

        while (*str == ' ') 
            str++;
        
        bool positive = true;
        if (*str == '+') {
            ++str;
        } else if (*str == '-') {
            positive = false;
            ++str;
        }
        
        long long val = 0;
        while(*str != '\0') {
            const char c = *str;
            ++str;
            if (c >= '0' && c <= '9') {
                val = (val * 10) + (c - '0');
                if (val > INT_MAX) {
                    break;
                }
            } else {
                break;
            }
        };

        if (val == 0) {
            return val;
        }
        else if (val > INT_MAX) {
            return positive ? INT_MAX : INT_MIN;
        } else {
            return (positive ? val : -val);
        }        
    }
};


class Solution {
public:
    // s: [start, end]
    bool isPalindrome(const string &s, size_t start, size_t end) {
        if (start == end) {
            return true;
        }
        //const size_t len = end - start + 1;
        for (size_t i = start; i <= start + (end-start)/2; ++i) {
            if (s[i] != s[end - (i-start)]) {
                return false;
            }
        }
        return true;
        
    }
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const size_t size = s.size();
        size_t count = 0;
        size_t newStart = 0;
        for (size_t i = size - 1; i >= newStart; ) {
            if (isPalindrome(s, newStart, i)) {
                count += 1;
                newStart = i + 1;
                i = size - 1;
                continue;
            } else {
                --i;
            }
        }
        return count-1;
    }
};

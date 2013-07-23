class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const size_t size = s.size();
        if (size == 0) {
            return 0;
        }
        
        size_t prevLen = 0, start = 0, end = 0;
        for (size_t i = 0; i < size; ++i) {
            if (i != 0) {
                for (size_t j = start; j <= end; ++j) {
                    if (s[j] == s[i]) {
                        const size_t curLen = end - start + 1;
                        if (curLen > prevLen) {
                            prevLen = curLen;
                        }
                        start = j+1;
                        break;
                    }
                }                
            }
            end = i;
        }
        const size_t curLen = end - start + 1;
        return (curLen > prevLen) ? curLen : prevLen;
    }
};


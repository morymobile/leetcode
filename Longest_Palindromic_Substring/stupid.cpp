class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const int size = s.size();
        string ret;
        for (int i = 0; i < size; ++i) {
            const int mid = i;
            for (int j = 1; j <= min(mid, size - mid - 1); ++j) {
                if (s[mid-j] == s[mid+j]) {
                    if (j*2+1 > ret.size()) {
                        ret = s.substr(mid-j, j*2+1);                        
                    }
                } else {
                    break;
                }
            }
            for (int j = 0; j <= min(mid, size - mid - 1); ++j) {
                if (s[mid-j] == s[mid+j+1]) {
                    if ((j+1)*2 > ret.size()) {
                        ret = s.substr(mid-j, (j+1)*2);
                    }
                } else {
                    break;
                }
            }
        }
        if (ret.empty())
            ret = s.substr(0, 1);
        return ret;
    }
};

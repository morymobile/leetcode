class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        /*
        vector<int> pos(256, -1);
        int begin = 0, ret = 0;
        for (int i = 0; i < s.size(); ++i) {
            begin = max(begin, pos[s[i]] + 1);
            pos[s[i]] = i;
            ret = max(ret, i - begin + 1);
        }
        return ret;
        */
        if (s.empty()) {
            return 0;
        }
        bool exist[256] = {false};
        const size_t size = s.size();
        size_t pos = 0, start = 0, end = 0;
        int ret = 0;
        while (pos < size) {
            const char v = s[pos];
            if (exist[v]) {
                ret = max(ret, (int)(end - start + 1));
                while (s[start] != v) {
                    exist[s[start++]] =false;
                }
                start++;
            } else {
                exist[v] = true;
            }
            end = pos++;
        }
        return max(ret, (int)(end - start + 1));
    }
};


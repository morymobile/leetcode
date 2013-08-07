class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const int size = strs.size();
        //vector<int> lengths;
        int minIndex = -1, minLength = INT_MAX;
        for (int i = 0; i < size; ++i) {
            const int len = strs[i].size();
            if (len < minLength) {
                minLength = len;
                minIndex = i;
            }
        }
        
        int i = 0;
        for (; minIndex >= 0 && i < minLength; ++i) {
            bool end = false;
            for (int j = 0; j < size; ++j) {
                const string &str = strs[j];
                if (str[i] != strs[minIndex][i]) {
                    end = true;
                    break;
                }
            }
            if (end) {
                break;
            }
        }
        return (i > 0) ? strs[minIndex].substr(0, i) : "";
    }
};

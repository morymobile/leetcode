class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty())
            return "";

        const int size = strs.size();
        const int len = strs[0].size();
        for (int i = 0; i < len; ++i) {
            for (int j = 1; j < size; ++j) {
                if (i >= strs[j].size() || strs[j][i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

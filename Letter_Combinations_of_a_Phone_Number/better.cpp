class Solution {
public:
    void func(vector<string> &ret, const string &digits, const string &str, int pos = 0) {
        static const string numStrs[] =
            {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        static const int numStrsLen = 10;
        
        if (pos == digits.size()) {
            return ret.push_back(str);
        }
        
        const int c = (int)(digits[pos] - '0');
        if (c >= numStrsLen || c < 0) {
            return func(ret, digits, str, pos+1);
        }
        
        const string &tmp = numStrs[c];
        for (size_t i = 0; i < tmp.size(); ++i) {
            func(ret, digits, str + tmp[i], pos+1);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        func(ret, digits, "", 0);
        return ret;
    }
};

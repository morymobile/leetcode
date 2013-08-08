class Solution {
public:
    //static string[] = {"", }
    void func(vector<string> &ret, const string &digits, const string &str, int pos = 0) {
        if (pos == digits.size()) {
            ret.push_back(str);
        }
        
        const char c = digits[pos];
        if (c >= '2' && c <= '7') {
            int n = c - '2';
            int max = (c == '7') ? 4 : 3;
            for (int i = 0; i < max; ++i) {
                const char newc = ('a' + n*3 + i);
                string newstr = str + newc;
                func(ret, digits, newstr, pos+1);
            }
        }
        if (c >= '8' && c <= '9') {
            int n = c - '8';
            int max = (c == '9') ? 4 : 3;
            for (int i = 0; i < max; ++i) {
                const char newc = ('t' + n*3 + i);
                string newstr = str + newc;
                func(ret, digits, newstr, pos+1);
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        func(ret, digits, "", 0);
        return ret;
    }
};

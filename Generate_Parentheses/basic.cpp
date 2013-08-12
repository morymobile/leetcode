class Solution {
public:
    void generate(set<string> &uret, int n, string &str) {
        if (n == 0) {
            uret.insert(str);
            return;
        }
        
        map<size_t, size_t> startEndMap;
        int start = -1, end = -1;
        const size_t size = str.size();
        for (int i = 0; i < size; ++i) {
            if (str[i] == 0) {
                if (start == -1) {
                    start = i;
                } else {
                    end = i;
                }
            } else {
                if (start >= 0 && end > start) {
                    startEndMap[start] = end;
                    start = -1;
                    end = -1;
                }
            }
        }
        if (start >= 0 && end > start)
            startEndMap[start] = end;
        
        for (map<size_t, size_t>::const_iterator it = startEndMap.begin();
            it != startEndMap.end(); ++it) {
            const int s = it->first, e = it->second;
            for (int i = s+1; i <= e; i += 2) {
                string tmp = str;
                tmp[s] = '(';
                tmp[i] = ')';
                generate(uret, n-1, tmp);
            }
                
        }
    }
    
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        set<string> uret;
        string str(n*2, 0);
        generate(uret, n, str);

        vector<string> ret;
        copy(uret.begin(), uret.end(), back_inserter(ret));
        return ret;
    }
};

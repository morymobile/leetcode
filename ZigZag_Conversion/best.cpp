class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
    
        if (nRows == 1)
            return s;

        vector<string> strRows(nRows, "");
        const int size = s.size();
        bool down = true;
        for (int i = 0, row = 0; i < size; ++i) {
            if (down) {
                strRows[row++] += s[i];
            } else {
                strRows[row--] += s[i];
            }
            if (down && row == nRows) {
                down = false;
                row -= 2;
            }
            if (!down && row == -1) {
                down = true;
                row += 2;
            }
        }

        string ret;
        for (int j = 0; j < nRows; ++j) {
            ret += strRows[j];
        }
        return ret;
    }
};

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        vector<string> strRows(nRows);
        const int size = s.size();
        for (int i = 0, idx = 0; i < size;) {
            const int col = idx % nRows;
            cout << "i, idx, col:" << i << "," << idx << "," << col << "," << (idx / nRows) << endl;
            if ((idx / nRows) % 2 == 0 || (col > 0 && col < nRows - 1)) {
                string &tmp = strRows[col];
                tmp += s[i];
                ++i;
            }
            ++idx;
        }
        string ret;
        for (int i = 0; i < nRows; ++i) {
            ret += strRows[i];
        }
        return ret;
    }
};

int main()
{
    Solution s;
    cout << s.convert("PAYPALISHIRING", 2) << endl;    
    cout << s.convert("PAYPALISHIRING", 4) << endl;    

    return 0;
}

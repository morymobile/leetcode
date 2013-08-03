#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool hit(int *prevCols, int *prevRows, int curCol, int curRow, int nRows) {
        if(prevCols[0] == -1)
            return true;

        if(prevRows[1] == 0
            && curRow - prevRows[1] == 1
            && curCol == prevCols[1])
            return true;

        if(prevCols[1] == prevCols[0]
            && curCol == prevCols[1]
            && curRow - prevRows[1] == 1)
            return true;

        if(prevRows[1] == nRows - 1
            && abs(prevRows[1] - curRow) == 1
            && curCol == prevCols[1] + 1)
            return true;

        if((prevCols[1] - prevCols[0]) == 1 && (prevRows[0] - prevRows[1]) == 1) {
            if ((curCol - prevCols[1]) == 1 && (curRow - prevRows[1]) == -1)
                return true;
        }
        return false;
    }
    
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if (nRows == 1)
            return s;

        vector<string> strRows(nRows);
        const int size = s.size();
        int prevCols[2] = {-1, -1}, prevRows[2] = {-1, -1};

        for (int i = 0, idx = 0; i < size;) {
            const int col = idx / nRows;
            const int row = idx % nRows;
            cout << "i:" << i << " idx:" << idx << " col:" << col << " row:" << row << endl;
            if (hit(prevCols, prevRows, col, row, nRows)) {
                cout << "c:" << s[i] << endl;
                strRows[col] += s[i++];
                prevCols[0] = prevCols[1];
                prevRows[0] = prevRows[1];
                prevCols[1] = col;
                prevRows[1] = row;
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

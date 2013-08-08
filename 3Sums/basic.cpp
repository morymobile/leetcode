#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
/* drafts
2, 3, 4, 5, 1
2, 3, 4, 5, 6

2, 5, 0, 7, 6, 4

7, 3, 8, 6, 2, 4
3, 7,
   2        7

*/
    int partition(vector<int> &num, int i, int j) {
        if (i >= j)
            return -1;
        
        const int val = num[j];
        int cursor = -1, k = 0;
        while (k <= j-1) {
            if (num[k] <= val) {
                ++cursor;
                if (k != cursor) {
                    std::swap(num[k], num[cursor]);
                }
            }
            ++k;
        };
        ++cursor;
        if (cursor != j) {
            swap(num[cursor], num[j]);            
        }
        return cursor;
    }
    
    void sortArray(vector<int> &num, int i, int j) {
        if (i < j) {
            const int k = partition(num, i, j);
            sortArray(num, i, k-1);
            sortArray(num, k+1, j);            
        }
    }
    
    void sortArray(vector<int> &num) {
        sortArray(num, 0, num.size()-1);
    }

    vector<vector<int> > threeSum(vector<int> &num) {
        const int size = num.size();
        vector<vector<int> > ret;
        if (size < 3)
            return ret;

        sortArray(num, 0, num.size() - 1);
        
        int rightMost = size;
        for (int i = 0; i < size; ++i) {
            for (int j = i+1; j < size; ++j) {
                const int next = -(num[i] + num[j]);
                for (int k = j+1; k < rightMost; ++k) {
                    if (num[k] == next) {
                        vector<int> item(3, num[i]);
                        item[1] = num[j];
                        item[2] = num[k];
                        ret.push_back(item);
                        rightMost = k;
                        break;
                    }
                    else if (num[k] > next) {
                        break;
                    }
                }
            }
        }
        
        return ret;
    }
};

static void converStrToNums(const std::string &str, vector<int> &num)
{
    int begin = 0, cur = 0;
    const int len = str.size();
    while (cur <= len) {
        if (str[cur] == ',') {
            num.push_back(atoi(str.substr(begin, cur-begin).c_str()));
            begin = cur+1;
        }
        ++cur;
    };
}

static void printArray(const vector<int> &num)
{
    std::cout << "\nprint num:\n";
    for (size_t i = 0; i < num.size(); ++i) {
        std::cout << num[i] << ", ";
    }
    std::cout << "\n\n";
}

int main()
{
    vector<int> num;
    const std::string str = "-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6";
    converStrToNums(str, num);

    printArray(num);
    Solution().sortArray(num);
    printArray(num);
    return 0;
}

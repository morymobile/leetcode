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
    
    vector<vector<int> > threeSum(vector<int> &num) {
        const int size = num.size();
        vector<vector<int> > ret;
        if (size < 3)
            return ret;

        set<vector<int> > uniqret;
        sortArray(num, 0, num.size() - 1);
        
        for (int i = 0; i < size; ++i) {
            int rightMost = size;
            for (int j = i+1; j < size; ++j) {
                const int next = -(num[i] + num[j]);
                for (int k = j+1; k < rightMost; ++k) {
                    if (num[k] == next) {
                        vector<int> item(3, num[i]);
                        item[1] = num[j];
                        item[2] = num[k];
                        uniqret.insert(item);
                        rightMost = k;
                        break;
                    }
                    else if (num[k] > next) {
                        break;
                    }
                }
            }
        }
        for (set<vector<int> >::iterator it = uniqret.begin(); it != uniqret.end(); ++it) {
            ret.push_back(*it);
        }
        return ret;
    }
};


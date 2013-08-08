class Solution {
public:
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
        std::sort(num.begin(), num.end());
        /*
        if (i < j) {
            const int k = partition(num, i, j);
            sortArray(num, i, k-1);
            sortArray(num, k+1, j);            
        }
        */
    }
    
    vector<vector<int> > threeSum(vector<int> &num) {
        const int size = num.size();
        vector<vector<int> > ret;
        if (size < 3)
            return ret;

        sortArray(num, 0, num.size() - 1);
        
        vector<int> item(3, 0);
        set<vector<int> > uniqret;
        for (int i = 0; i < size; ++i) {
            const int expected = -num[i];
            int j = i+1, k = size-1;
            while(j < k) {
                const int twosum = num[j] + num[k];
                if (twosum > expected) {
                    --k;
                } else if (twosum < expected) {
                    ++j;
                } else {
                    item[0] = num[i];
                    item[1] = num[j];
                    item[2] = num[k];
                    uniqret.insert(item);
                    --k;
                    ++j;
                }
            }
        }
        /*
        for (set<vector<int> >::iterator it = uniqret.begin(); it != uniqret.end(); ++it) {
            ret.push_back(*it);
        }
        */
        std::copy(uniqret.begin(), uniqret.end(), back_inserter(ret));
        return ret;
    }
};


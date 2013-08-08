class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        const size_t size = num.size();
        if (size < 4) {
            return ret;
        }
        
        std::sort(num.begin(), num.end());
        
        map<int, int> value2Index;
        for (size_t i = 0; i < size; ++i) {
            for (size_t j = i+1; j < size; ++j) {
                const int v = num[i] + num[j];
                if (value2Index.find(v) == value2Index.end()) {
                    value2Index[v] = i+j;
                } else {
                    value2Index[v] += i+j;
                }
            }
        }
        
        set<vector<int> > uitems;
        vector<int> item(4, 0);
        for (size_t i = 0; i < size; ++i) {
            const int ni = num[i];
            for (size_t j = i+1; j < size; ++j) {
                const int nj = num[j];
                const int expected = target - ni - nj;
                if (value2Index[expected] == 0 || value2Index[expected] == i+j) {
                    continue;
                }
                
                size_t k = j+1, l = size-1;
                while (k < l) {
                    const int twosum = num[k] + num[l];
                    if (twosum < expected) {
                        ++k;
                    } else if (twosum > expected) {
                        --l;
                    } else {
                        item[0] = ni;
                        item[1] = nj;
                        item[2] = num[k];
                        item[3] = num[l];
                        uitems.insert(item);
                        ++k;
                        --l;
                    }
                }
            }
        }
        
        std::copy(uitems.begin(), uitems.end(), std::back_inserter(ret));
        return ret;
    }
};


class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        const size_t size = num.size();
        int ret = 0;
        if (size <= 3) {
            for (size_t i = 0; i < size; ++i) {
                ret += num[i];
            }
            return ret;
        }
        
        bool initialized = false;
        std::sort(num.begin(), num.end());
        for (size_t i = 0; i < size; ++i) {
            const int expected = target - num[i];
            int j = i+1, k = size-1;
            while(j < k) {
                const int twosum = num[j] + num[k];
                if (!initialized) {
                    ret = num[i] + twosum;
                    initialized = true;
                }
                
                const int current = num[i] + twosum;
                const int curDelta = current - target;
                if (abs(curDelta) < abs(ret - target)) {
                    ret = current;
                }
                
                if (curDelta == 0) {
                    return current;
                } else if (curDelta < 0) {
                    ++j;
                } else {
                    --k;
                }
            }
        }
        return ret;
    }
};


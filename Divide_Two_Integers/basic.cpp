class Solution {
public:
    int divide(int dividend, int divisor) {
        const bool positive = ((dividend >= 0) == (divisor >= 0));
        long long left = fabs((long long)dividend);
        long long right = fabs((long long)divisor);
        
        long long count = 0;
        while (left >= right) {
            
            //for (long long tmp = right, i = 0; left >= tmp; tmp = right << ++i) {
            for (long long tmp = right, i = 0; left >= tmp; i++, tmp <<= 1) {
                left -= tmp;
                count += (1<<i);
                
            }
        }
        return positive ? count : -count;
    }
};

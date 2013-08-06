class Solution {
public:
    string intToRoman(int num) {
        assert(num >= 1 && num <= 3999);

        //                 0    1    2    3    4    5    6
        char letters[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        //                 1    5    10   50   100  500  1000

        string ret;
        int i = 0;
        while (num != 0) {
            int mod = num%10;
            if(mod == 0) {
                
            } else if(mod >= 1 && mod <= 3) {
                ret = string(mod, letters[i*2 + 0]) + ret;
            } else if(mod == 4) {
                ret = string(1, letters[i*2 + 0]) + string(1, letters[i*2 + 1]) + ret;
            } else if(mod == 5) {
                ret = string(1, letters[i*2 + 1]) + ret;
            } else if(mod >= 6 && mod <= 8) {
                ret = string(1, letters[i*2 + 1]) + string(mod-5, letters[i*2 + 0]) + ret;
            } else if(mod == 9) {
                ret = string(1, letters[i*2 + 0]) + string(1, letters[i*2 + 2]) + ret;
            }
            num /= 10;
            ++i;
        }
        return ret;
    }
};


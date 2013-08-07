class Solution {
public:
    int romanToInt(string s) {
        //static const char numbers[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        //                              1    5    10   50   100  500  1000
        //                              0    1    2    3    4    5    6

        map<char, int> number2Value;
        number2Value['I'] = 1;
        number2Value['V'] = 5;
        number2Value['X'] = 10;
        number2Value['L'] = 50;
        number2Value['C'] = 100;
        number2Value['D'] = 500;
        number2Value['M'] = 1000;
        
        int ret = 0;
        char prev = '\0';
        
        const int size = s.size();
        for (int i = 0; i < size; ++i) {
            const char c = s[i];
            if (prev == '\0' || number2Value[c] <= number2Value[prev]) {
                ret += number2Value[c];
            } else {
                ret += (number2Value[c] - number2Value[prev] * 2);
            }
            prev = c;
        }
        
        return ret;
    }
};

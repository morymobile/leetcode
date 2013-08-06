#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        //assert(num >= 1 && num <= 3999);

        //                 0    1    2    3    4    5    6
        char letters[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        //                 1    5    10   50   100  500  1000

        string ret;
        int i = 0;
        while (num != 0) {
            int mod = num%10;
            std::cout << "mod: " << mod << std::endl;
            if(mod == 0) {
                std::cout << "mod: 0:" << ret << std::endl;
            } else if(mod >= 1 && mod <= 3) {
                ret = string(letters[i*2 + 0], mod) + ret;
                std::cout << "mod: 13:" << letters[i*2 + 0] << string(letters[i*2 + 0], mod) << std::endl;
            } else if(mod == 4) {
                ret = string(letters[i*2 + 0], 1) + string(letters[i*2 + 1], 1) + ret;
                std::cout << "mod: 4:" << ret << std::endl;
            } else if(mod == 5) {
                ret = string(letters[i*2 + 1], 1) + ret;
            } else if(mod >= 6 && mod <= 8) {
                ret = string(letters[i*2 + 1], 1) + string(letters[i*2 + 0], mod-5) + ret;
            } else if(mod == 9) {
                ret = string(letters[i*2 + 0], 1) + string(letters[i*2 + 2], 1) + ret;
            }
            num /= 10;
            ++i;
        }
        return ret;
    }
};


int main()
{
    std::cout << "intToRome: " << Solution().intToRoman(1) << std::endl;
    return 0;
}

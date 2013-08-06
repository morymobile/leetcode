#include <iostream>
#include <string>

class Solution {
public:

    /*
    bool isMatch(const char *s, const char *p) {
    if (*s == '\0' && *p == '\0')
            return true;

        if (*(p+1) != '*') {
            return ((*s == *p) || (*s != '\0' && *p == '.')) && isMatch(s+1, p+1);
        } else {
            int i = 0;
            while ((*(s+i) == *p) || (*p == '.' && *(s+i) != '\0')) {
                if(isMatch(s+i+1, p))
                    return true;
                ++i;
            };            
            return isMatch(s, p+2);
        }
    }
    */

    bool isMatch(const char *s, const char *p) {
        if (*p == '\0')
            return *s == '\0';

        if (*(p+1) != '*') {
            return ((*s == *p) || (*s != '\0' && *p == '.')) && isMatch(s+1, p+1);
        } else {
            int i = 0;
            while ((*(s+i) == *p) || (*p == '.' && *(s+i) != '\0')) {
                if(isMatch(s+i+1, p+2))
                    return true;
                ++i;
            };            
            return isMatch(s, p+2);
        }
    }

};

int main() {
    std::string s = "aaaaaaaaaaaaab";
    std::string p = "a*a*a*a*a*a*a*a*a*a*c";
    std::cout << "s: " << s << "\np: " << p << "\nresult: " << Solution().isMatch(s.c_str(), p.c_str()) << "\n";
}

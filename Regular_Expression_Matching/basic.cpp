class Solution {
public:
    bool isMatchSub(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if (*s == '\0' && *p == '\0')
            return true;
        //if (*s == '\0' || *p == '\0')
        //    return false;
        
        if (*s != '\0' && *p == '\0')
            return false;
        
        if (*(p+1) == '*') {
            if (*p == '.') {
                char *tmp = (char *)s;
                while (*tmp != '\0') {
                    if (isMatchSub(tmp, p+2)) {
                        return true;
                    } else {
                        ++tmp;
                    }
                };
                return isMatchSub(tmp, p+2);
            } else {
                if (*s == *p) {
                    char *tmp = (char *)s;
                    while (*tmp == *s) {
                        if (isMatchSub(tmp+1, p+2)) {
                            return true;
                        } else {
                            ++tmp;
                        }
                    };
                    return isMatchSub(s, p+2);
                } else {
                    return isMatchSub(s, p+2);
                }
            }
        } else {
            if (*p == '.') {
                return *s != '\0' && isMatchSub(s+1, p+1);
            } else {
                return (*s == *p && isMatchSub(s+1, p+1));
            }
        }
    }

    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if (s == NULL && p == NULL)
            return true;
        if (s == NULL || p == NULL)
            return false;
            
        char *ptemp = (char *)p;
        do {
            if (isMatchSub(s, ptemp))
                return true;
            ++ptemp;
            if (*ptemp == '*')
                ++ptemp;
            else
                return false;
        } while(*ptemp != '\0');
        return false;
  }
    
};

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (haystack == NULL || needle == NULL)
            return NULL;
        
        if (*haystack == '\0') {
            if (*needle == '\0') {
                return haystack;
            } else {
                return NULL;
            }
        }
        
        while (*haystack != '\0') {
            char *l = haystack, *r = needle;
            while (*l != '\0' && *r != '\0' && *l == *r) {
                ++l;
                ++r;
            }
            if (*r == '\0') {
                return haystack;
            }
            if (*l == '\0') {
                return NULL;
            }
            ++haystack;
        }
        
        return NULL;
    }
};

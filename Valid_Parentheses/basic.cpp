class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        map<char, char> c2c;
        c2c[')'] = '(';
        c2c[']'] = '[';
        c2c['}'] = '{';

        string stack;
        const size_t size = s.size();
        for (int i = 0; i < size; ++i) {
            const char c = s[i];
            if (c == '(' || c == '{' || c == '[') {
                stack.push_back(c);
            } else if (c == ')' || c == '}' || c == ']') {
                if (!stack.empty() && stack.back() == c2c[c]) {
                    stack.pop_back();
                } else {
                    stack.push_back(c);
                }
            }
        }
        
        return stack.empty();
    }
};

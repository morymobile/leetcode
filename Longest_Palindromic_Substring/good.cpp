class Solution {
public:
    string prepare(const string &s) {
        if (s.empty())
            return "#";
        string t = "#";
        for(int i = 0; i < s.size(); ++i) {
            t += (s[i] + "#");
        }
        return t;
    }
    
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.empty())
            return "";
            
        const string t = prepare(s);
        const int size = t.size();
        vector<int> counts(size, 0);

        int maxIndex = -1;
        for (int i = 0; i < size; ++i) {
            const int mid = i;
            int count = 0;
            for (int j = 1; j <= min(mid, size - mid - 1); ++j) {
                if (t[mid-j] == t[mid+j]) {
                    ++count;
                } else {
                    break;
                }
            }
            counts[mid] = count;
            if (maxIndex == -1) {
                maxIndex = mid;
            } else if (count > counts[maxIndex]) {
                maxIndex = mid;
            }
        }
        
        if (maxIndex == -1)
            return s.substr(0, 1);
        return s.substr((maxIndex - counts[maxIndex] - 1)/2, counts[maxIndex]);
    }
};

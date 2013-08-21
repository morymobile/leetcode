class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 1)
            return n;

        int size = n;
        int prevIndex = 0;
        for (int i = 1; i < size; ++i) {
            if (A[i] != A[prevIndex]) {
                if (prevIndex+1 == i) {
                    prevIndex = i;
                } else {
                    for (int j = i; j < size; ++j) {
                        A[prevIndex+j-i+1] = A[j];
                    }
                    size -= (i-prevIndex-1);
                    ++prevIndex;
                    i = prevIndex;
                }
            }
        }
        return prevIndex+1;
    }
};

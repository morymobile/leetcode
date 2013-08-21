class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 1)
            return n;

        int size = n;
        int prevIndex = 0;
        for (int i = 1; i < size; ++i) {
            if (A[i] != A[prevIndex]) {
                if (prevIndex+1 == i) {
                    prevIndex = i;
                } else {
                    memmove((void *)(A+prevIndex+1), (const void *)(A+i), (size-i)*sizeof(int));
                    size -= (i-prevIndex-1);
                    ++prevIndex;
                    i = prevIndex;
                }
            }
        }
        return prevIndex+1;
    }
};

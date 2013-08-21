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
                    //NOTE: memcpy couldn't handle overlap memory spaces.
                    // While memmove could handle that with intermediate buffer.
                    //memcpy((void *)(A+prevIndex+1), (const void *)(A+i), (size-i)*sizeof(int));
                    /*
                    for (int j = i; j < size; ++j) {
                        A[prevIndex+j-i+1] = A[j];
                    }
                    */
                    size -= (i-prevIndex-1);
                    ++prevIndex;
                    i = prevIndex;
                }
            }
        }
        return prevIndex+1;
    }
};

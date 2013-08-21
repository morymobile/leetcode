class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        std::sort(A, A+n);
        int left = -1;
        for (int i = 0; i < n; ++i) {
            if (A[i] == elem) {
                if (left == -1)
                    left = i;
            } else {
                if (left != -1) {
                    memmove((void *)(A+left), (const void *)(A+i), sizeof(int) *(n-i));
                    return n - (i-left);
                }
            }
        }
        if (left != -1) {
            return left;
        }
        return n;
    }
};

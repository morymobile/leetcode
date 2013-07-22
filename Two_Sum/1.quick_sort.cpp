#include <algorithm>

class Solution {
public:

    int sortPartition(std::vector<int> &numbers, int start, int end)
    {
        const int x = numbers[end];
        int i = start - 1;
        for (int j = start; j < end; ++j) {
            if (numbers[j] <= x) {
                i = i+1;
                if (i != j) {
                    const int tmp = numbers[i];
                    numbers[i] = numbers[j];
                    numbers[j] = tmp;
                }
            }
        }
        i = i+1;
        if (i != end) {
            const int tmp = numbers[i];
            numbers[i] = numbers[end];
            numbers[end] = tmp;
        }
        return i;
    }
    
    void quickSort(std::vector<int> &numbers, int start, int end)
    {
        if (start < end) {
            const int q = sortPartition(numbers, 0, numbers.size() - 1);
            sortPartition(numbers, start, q - 1);
            sortPartition(numbers, q + 1, end);
        }
    }
    
    void sort(vector<int> &numbers) {
        quickSort(numbers, 0, numbers.size() - 1);
    }
    
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(numbers);
        
        int index1 = 0, index2 = -1;
        int value2 = target - numbers[index1];
        
        const size_t size = numbers.size();
        size_t right = size;
        for (size_t i = 1; i < right; ) {
            if (numbers[i] == value2) {
                index2 = i;
                break;
            } else if (numbers[i] > value2) {
                right = i;
                ++index1;
                value2 = target - numbers[index1];
                i = index1+1;
            } else {
                ++i;
            }
        }
        
        vector<int> indices;
        indices.push_back(index1+1);
        indices.push_back(index2+1);
        return indices;
    }
};


#include <algorithm>

class Solution {
public:

    int sortPartition(std::vector<int> &numbers, int start, int end, std::vector<int> &indices)
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
                    const int tmpIndex = indices[i];
                    indices[i] = indices[j];
                    indices[j] = tmpIndex;
                }
            }
        }
        i = i+1;
        if (i != end) {
            const int tmp = numbers[i];
            numbers[i] = numbers[end];
            numbers[end] = tmp;
            const int tmpIndex = indices[i];
            indices[i] = indices[end];
            indices[end] = tmpIndex;
        }
        return i;
    }
    
    void quickSort(std::vector<int> &numbers, int start, int end, std::vector<int> &indices)
    {
        if (start < end) {
            const int q = sortPartition(numbers, start, end, indices);
            quickSort(numbers, start, q - 1, indices);
            quickSort(numbers, q + 1, end, indices);
        }
    }
    
    std::vector<int> sort(vector<int> &numbers) {
        const int size = numbers.size();
        std::vector<int> indices;
        for (int i = 0; i < size; ++i) {
            indices.push_back(i);
        }
        quickSort(numbers, 0, size - 1, indices);
        return indices;
    }
    
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> tmp = numbers;
        std::vector<int> indices = sort(tmp);
        
        int index1 = 0, index2 = -1;
        int value2 = target - numbers[indices[index1]];
        
        const size_t size = indices.size();
        size_t right = size;
        for (size_t i = 1; i < right; ) {
            if (numbers[indices[i]] == value2) {
                index2 = i;
                break;
            } else if (numbers[indices[i]] > value2) {
                right = i;
                ++index1;
                value2 = target - numbers[indices[index1]];
                i = index1+1;
            } else {
                ++i;
            }
        }
        
        vector<int> result;
            result.push_back(indices[index1] + 1);
            result.push_back(indices[index2] + 1);
/*
        if (indices[index1] < indices[index2]) {
            result.push_back(indices[index1] + 1);
            result.push_back(indices[index2] + 1);
        } else {
            result.push_back(indices[index2] + 1);
            result.push_back(indices[index1] + 1);
        }*/
        return result;
    }
};


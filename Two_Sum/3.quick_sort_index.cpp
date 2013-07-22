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
                    std::swap(numbers[i], numbers[j]);
                    std::swap(indices[i], indices[j]);
                }
            }
        }
        ++i;
        if (i != end) {
            std::swap(numbers[i], numbers[end]);
            std::swap(indices[i], indices[end]);
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
        vector<int> tmp = numbers;
        const std::vector<int> indices = sort(tmp);
        
        int index1 = 0, index2 = -1, indexNext = 1;
        int value2 = target - numbers[indices[index1]];
        
        const size_t size = indices.size();
        size_t right = size, i = 1;
        while (indexNext < right) {
            if (numbers[indices[indexNext]] == value2) {
                index2 = indexNext;
                break;
            } else {
                if (numbers[indices[indexNext]] > value2) {
                    right = indexNext;
                } else {
                    ++indexNext;
                    if (indexNext != right) {
                        continue;
                    }
                }

                ++index1;
                value2 = target - numbers[indices[index1]];
                indexNext = index1+1;
            }
        }
        
        index1 = indices[index1] + 1;
        index2 = indices[index2] + 1;
        
        vector<int> result;
        if (index1 < index2) {
            result.push_back(index1);
            result.push_back(index2);
        } else {
            result.push_back(index2);
            result.push_back(index1);
        }
        return result;
    }
};


#include <iostream>
#include <vector>

class Solution
{
private:
    std::vector<int> &sort(std::vector<int> &nums)
    {
        std::vector<int> sorted(nums);

        mergeSort(sorted, 0, sorted.size() - 1);

        return sorted;
    }

    void mergeSort(std::vector<int> &nums, int start, int end)
    {
        while (start < end)
        {
            int mid = (start + end) / 2;
            mergeSort(nums, start, mid);
            mergeSort(nums, mid + 1, end);
            merge(nums, start, mid, end);
        }
    }

    void merge(std::vector<int> nums, int beg, int mid, int end)
    {
        int i, j, k;
        int n1 = mid - beg + 1;
        int n2 = end - mid;

        int leftArray[n1], rightArray[n2]; // temporary arrays

        /* copy data to temp arrays */
        for (int i = 0; i < n1; i++)
            leftArray[i] = nums[beg + i];
        for (int j = 0; j < n2; j++)
            rightArray[j] = nums[mid + 1 + j];

        i = 0;   /* initial index of first sub-array */
        j = 0;   /* initial index of second sub-array */
        k = beg; /* initial index of merged sub-array */

        while (i < n1 && j < n2)
        {
            if (leftArray[i] <= rightArray[j])
            {
                nums[k] = leftArray[i];
                i++;
            }
            else
            {
                nums[k] = rightArray[j];
                j++;
            }
            k++;
        }
        while (i < n1)
        {
            nums[k] = leftArray[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            nums[k] = rightArray[j];
            j++;
            k++;
        }
    }

public:
    std::vector<std::vector<int>> divideArray(std::vector<int> &nums, int k)
    {
        auto sorted = sort(nums);
    }
};

int main()
{
    std::vector<int> nums = {1, 3, 4, 8, 7, 9, 3, 5, 1};
    int k = 2;
    Solution s;
    s.divideArray(nums, k);
    return 0;
}
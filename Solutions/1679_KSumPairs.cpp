#include <bits/stdc++.h>

class Solution
{
public:
    int maxOperations(std::vector<int> &nums, int k)
    {
        int ops = 0;
        std::sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            if (nums[i] + nums[j] < k)
                i++;
            else if (nums[i] + nums[j] > k)
                j--;
            else
            {
                i++;
                j--;
                ops++;
            }
        }

        return ops;
    }
};

int main()
{
    Solution s;
    std::vector<int> nums = {1, 2, 3, 6};
    std::cout << s.maxOperations(nums, 5);
    return 0;
}
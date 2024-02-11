#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {
        if (nums.size() < 3)
            return {};

        std::sort(nums.begin(), nums.end());
        std::unordered_set<int> cache(nums.begin(), nums.end());
        int target = 0;

        std::vector<std::vector<int>> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            int left = i + 1, right = nums.size() - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == target)
                {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                }
                else if (sum < target)
                {
                    left++;
                }
                else
                    right--;
            }
        }
    }
};

int main()
{
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    //-4, -1, -1, 0 , 1, 2
    Solution s;
    s.threeSum(nums);
}
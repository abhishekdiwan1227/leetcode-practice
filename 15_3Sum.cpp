#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (i != 0 && nums[i - 1] == nums[i])
                continue;
            else
            {
                auto match = twoSum(nums, -nums[i], i + 1, nums.size() - 1);
                if (!match.empty())
                {
                    for (auto m : match)
                    {
                        res.push_back({nums[i], nums[m[0]], nums[m[1]]});
                    }
                }
            }
        }
        return res;
    }

private:
    std::vector<std::vector<int>> twoSum(std::vector<int> nums, int target, int start, int end)
    {
        std::vector<std::vector<int>> res;
        while (start < end)
        {
            if (nums[start] + nums[end] > target || (nums[end] == nums[end - 1] && end - 1 != start))
                end--;
            else if (nums[start] + nums[end] < target || (nums[start] == nums[start + 1] && start + 1 != end))
                start++;
            else if (nums[start] + nums[end] == target)
            {
                res.push_back({start, end});
                start++;
                end--;
            }
        }
        return res;
    }
};

int main()
{
    std::vector<int> nums = {-5, -4, -2, 0, 1, 3, 4};
    Solution s;
    s.threeSum(nums);
}
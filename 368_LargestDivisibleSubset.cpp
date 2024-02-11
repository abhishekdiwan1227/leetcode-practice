#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution
{
public:
    std::vector<int> largestDivisibleSubset(std::vector<int> nums)
    {
        int len = nums.size();
        if (len == 1)
            return std::vector<int>{nums[0]};

        int max[len];
        int prev[len];
        int maxLength = 0, maxIndex = -1;
        std::fill_n(max, len, 1);
        std::fill_n(prev, len, -1);

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < len; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[i] % nums[j] == 0 && max[j] + 1 > max[i])
                {
                    max[i] = max[j] + 1;
                    prev[i] = j;
                }
            }

            if (max[i] > maxLength)
            {
                maxLength = max[i];
                maxIndex = i;
            }
        }

        std::vector<int> answer;

        while (maxIndex != -1)
        {
            answer.push_back(nums[maxIndex]);
            maxIndex = prev[maxIndex];
        }

        reverse(answer);

        return answer;
    }

private:
    void reverse(std::vector<int> &nums)
    {
        int i = 0;
        int j = nums.size() - 1;
        while (i < j)
        {
            std::swap(nums[i++], nums[j--]);
        }
    }
};

int main()
{
    std::vector<int> nums = {12, 7, 6, 3, 2};
    Solution s;
    std::vector<int> ans = s.largestDivisibleSubset(nums);
    for (auto i : ans)
        std::cout << i << "\n";
    return 0;
}
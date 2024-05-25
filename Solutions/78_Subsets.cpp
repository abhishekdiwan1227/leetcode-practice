#include <bits/stdc++.h>

class Solution
{
public:
    std::vector<std::vector<int>> subsets(std::vector<int> &nums)
    {
        std::set<std::vector<int>> results;

        int i = 0;
        std::vector<int> curr = {};
        generate(&results, i, nums, curr);

        for (auto a : results)
        {
            print(a);
        }

        return std::vector<std::vector<int>>(results.cbegin(), results.cend());
    }

private:
    void generate(std::set<std::vector<int>> *results, int i, std::vector<int> &nums, std::vector<int> curr)
    {
        results->insert(curr);
        if (i >= nums.size())
            return;

        std::cout << "i: " << i << std::endl;
        std::cout << "num: " << nums[i] << std::endl;

        std::cout << std::endl;

        generate(results, i + 1, nums, std::vector<int>(curr));

        curr.push_back(nums[i]);
        generate(results, i + 1, nums, std::vector<int>(curr));
    }

    void print(std::vector<int> a)
    {
        std::cout << "ans: ";
        for (auto i : a)
            std::cout << i << " ";
        std::cout << std::endl;
    }
};

int main()
{
    Solution s;
    std::vector<int> nums = {1, 2, 3};
    auto ans = s.subsets(nums);
    return 0;
}
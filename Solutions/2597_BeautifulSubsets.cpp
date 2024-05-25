#include <bits/stdc++.h>
#include <algorithm>

class Solution
{
public:
    int beautifulSubsets(std::vector<int> &nums, int k)
    {
        int count = 0;
        std::vector<int> subset;
        std::unordered_set<int> cache;
        dfs(nums, 0, {}, k, count, cache);
        return count;
    }

private:
    void dfs(const std::vector<int> &nums, int i, std::vector<int> subset, int k, int &count, std::unordered_set<int> &cache)
    {
        if (i >= nums.size())
            return;
        for (int j = i; j < nums.size(); j++)
        {
            subset.push_back(nums[j]);
            cache.insert(nums[j]);
            if (cache.find(nums[j] + k) == cache.end() && cache.find(nums[j] - k) == cache.end())
            {
                print(subset);
                std::cout << "True\n";
                count++;
                dfs(nums, j + 1, subset, k, count, cache);
            }
            subset.pop_back();
            cache.erase(nums[j]);
        }
    }

    void print(std::vector<int> subset)
    {
        std::cout << "<";
        for (int i = 0; i < subset.size(); i++)
        {
            std::cout << subset[i];
            if (i != subset.size() - 1)
                std::cout << ", ";
        }
        std::cout << ">";
        std::cout << std::endl;
    }
};

int main()
{
    std::vector nums{20, 14, 16, 3, 25, 12, 2, 19, 1, 9, 5, 22, 24, 7, 4, 21, 6, 28};

    // 4,42,

    int k = 1;
    Solution s;
    std::cout << s.beautifulSubsets(nums, k);
    return 0;
}
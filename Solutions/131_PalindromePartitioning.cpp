#include <bits/stdc++.h>

class Solution
{
public:
    std::vector<std::vector<std::string>> partition(std::string s)
    {
        std::vector<std::vector<std::string>> results;
        std::vector<std::string> ans;

        int i = 0;
        dfs(i, s, ans, results);

        return results;
    }

private:
    bool isPalindrome(std::string s, int i, int j)
    {
        while (i <= j)
        {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }

    void dfs(int i, std::string s, std::vector<std::string> &ans, std::vector<std::vector<std::string>> &results)
    {
        if (i >= s.length())
        {
            results.push_back(std::vector<std::string>(ans.cbegin(), ans.cend()));
            return;
        }
        for (int j = i; j < s.length(); j++)
        {
            if (isPalindrome(s, i, j))
            {
                int len = j - i == 0 ? 1 : j - i;
                ans.push_back(s.substr(i, len));
                dfs(j + 1, s, ans, results);
                ans.pop_back();
            }
        }
    }
};

// a a a b

int main()
{
    std::string s = "aab";
    Solution sol;

    auto ans = sol.partition(s);

    for (auto a : ans)
    {
        for (std::string b : a)
        {
            std::cout << b << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}
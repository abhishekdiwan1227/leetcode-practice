#include <bits/stdc++.h>

class Solution
{
public:
    std::vector<std::string> generateParantheses(int n)
    {
        std::vector<std::string> results;
        std::string current;

        dfs(results, current, 0, 0, n);

        return results;
    }

private:
    void dfs(std::vector<std::string>& results, std::string curr, int open, int close, int n)
    {
        if (open == n && close == n)
        {
            std::cout << curr << "\n";
            results.push_back(curr);
            return;
        }

        if (open < n)
            dfs(results, curr + "(", open + 1, close, n);
        if (close < open)
            dfs(results, curr + ")", open, close + 1, n);
    }
};

int main()
{
    Solution s;
    s.generateParantheses(3);
    return 0;
}
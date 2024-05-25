#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<std::string> generateParantheses(int n)
    {
        if (n == 0)
            return {};
        std::vector<std::string> ans;
        gen(ans, n - 1, n - 1, "");
        return ans;
    }

private:
    void gen(std::vector<std::string> &ans, int open, int close, std::string res)
    {
        if (open == 0 && close == 0)
        {
            res = "(" + res + ")";
            ans.push_back(res);
        }
        std::string curr = res;
        if (open > 0)
        {
            curr += "(";
            gen(ans, open - 1, close, curr);
        }
        if (close > 0)
        {
            curr += ")";
            gen(ans, open, close - 1, curr);
        }
    }
};

int main()
{
    Solution s;
    s.generateParantheses(3);
    return 0;
}
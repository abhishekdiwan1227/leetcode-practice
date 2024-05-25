#include <bits/stdc++.h>

class Solution
{
public:
    std::string countAndSay(int n)
    {
        std::string ans;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                ans = "1";
            else if (i == 1)
                ans = "11";
            else
            {
                std::string temp;
                int count = 1;
                for (int i = 1; i < ans.length(); i++)
                {
                    if (ans[i] == ans[i - 1])
                    {
                        count++;
                    }
                    else if (ans[i] != ans[i - 1])
                    {
                        temp += std::to_string(count) + ans[i - 1];
                        count = 1;
                    }
                    if(i == ans.length() - 1)
                    {
                        temp += std::to_string(count) + ans[i];
                    }
                }

                ans = temp;
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    std::cout << s.countAndSay(5);
    return 0;
}
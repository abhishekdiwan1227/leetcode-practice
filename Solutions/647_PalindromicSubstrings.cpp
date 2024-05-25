#include <iostream>

class Solution
{
public:
    int countSubstrings(std::string s)
    {
        int count = 0;
        int n = s.length();
        bool palindrome[n][n] = {false};

        for (int i = 0; i < n; i++)
        {
            palindrome[i][i] = true;
        }

        for (int i = 0; i < n - 1; ++i)
        {
            palindrome[i][i + 1] = s[i] == s[i + 1];
            count += palindrome[i][i + 1] ? 1 : 0;
        }

        for (int len = 3; len <= n; ++len)
            for (int i = 0, j = i + len - 1; j < n; ++i, ++j)
            {
                palindrome[i][j] = palindrome[i + 1][j - 1] && s[i] == s[j];
                count += palindrome[i][j] ? 1 : 0;
            }

        return count;
    }
};

int main()
{
    std::string s = "aaa";
    Solution sol;
    std::cout << sol.countSubstrings(s);
    return 0;
}
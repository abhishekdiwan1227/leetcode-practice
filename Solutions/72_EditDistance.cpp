#include <bits/stdc++.h>

class Solution
{
public:
    int minDistancne(std::string word1, std::string word2)
    {
        int n = word1.size();
        int m = word2.size();
        std::vector<std::vector<int>> mem(n + 1, std::vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++)
            mem[i][m] = n - i;
        for (int i = 0; i <= m; i++)
            mem[n][i] = m - i;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (word1[i] == word2[j])
                {
                    mem[i][j] = mem[i + 1][j + 1];
                }
                else
                {
                    int replace = mem[i + 1][j + 1];
                    int add = mem[i + 1][j];
                    int del = mem[i][j + 1];

                    mem[i][j] = 1 + std::min({replace, add, del});
                }
            }
        }

        return mem[0][0];
    }

private:
    int distance(std::string word1, std::string word2, int i, int j, int (&mem)[])
    {
        if (i == word1.length() && j == word2.length())
            return 0;
        if (word1[i] == word2[j])
            return distance(word1, word2, i + 1, j + 1, mem);
        if (i == word1.length() && j != word2.length())
            return 1 + distance(word1, word2, i, j + 1, mem);
        if (i != word1.length() && j == word2.length())
            return 1 + distance(word1, word2, i + 1, j, mem);
        else
        {
            int ins = 1 + distance(word1, word2, i + 1, j, mem);
            int del = 1 + distance(word1, word2, i, j + 1, mem);
            int rep = 1 + distance(word1, word2, i + 1, j + 1, mem);

            return std::min({ins, del, rep});
        }
    }
};

int main()
{
    Solution s;
    std::cout << s.minDistancne("horse", "ros");
    return 0;
}
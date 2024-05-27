#include <bits/stdc++.h>

class Solution
{
public:
    int maxVowels(std::string s, int k)
    {
        int n = s.length();
        int max = 0;

        int localMax = 0;
        int l = 0, r = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (isVowel(s[i]))
            {
                localMax++;
            }
            if (i == r)
                r++;
            if (r - l == k)
            {
                max = std::max(max, localMax);
                if (isVowel(s[l]))
                    localMax--;
                l++;
            }
        }
        return max;
    }

private:
    std::unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
    bool isVowel(char c)
    {
        return vowels.find(c) != vowels.cend();
    }
};

int main()
{
    Solution s;
    std::cout << s.maxVowels("weallloveyou", 7) << "\n";
    std::cout << s.maxVowels("aeiou", 2) << "\n";
    // 01234567891011
    // wealllovey o u
    //    i
    // l
    //    r

    // localmax = 2

    return 0;
}
#include <iostream>
#include <unordered_set>

class Solution
{
private:
    std::string vowels = "aeiouAEIOU";
    std::unordered_set<char> vowSet;

    int getAlikeIndex(std::string s)
    {
        int index = 0;
        for (std::string::const_iterator i = s.cbegin(); i != s.cend(); i++)
        {
            char c = *i;
            if (vowSet.find(c) != vowSet.end())
                index++;
        }
        return index;
    }

public:
    Solution() : vowSet(vowels.cbegin(), vowels.cend()) {}

    bool halvesAreAlike(std::string s)
    {
        int mid = s.length() / 2;
        std::string a = s.substr(0, mid);
        std::string b = s.substr(mid, mid);

        return getAlikeIndex(a) == getAlikeIndex(b);
    }
};

int main()
{
    std::string input = "textbook";
    Solution s;
    std::cout << s.halvesAreAlike(input);
    return 0;
}
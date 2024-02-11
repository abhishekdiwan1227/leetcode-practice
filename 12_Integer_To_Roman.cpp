#include <iostream>
#include <map>
#include <vector>

std::map<int, char> romanMapping = {
    {1, 'I'},
    {5, 'V'},
    {10, 'X'},
    {50, 'L'},
    {100, 'C'},
    {500, 'D'},
    {1000, 'M'}};

class Solution
{
public:
    std::string intToRoman(int num)
    {
        std::vector<int> intKeys;
        for (const auto &kvp : romanMapping)
        {
            intKeys.push_back(kvp.first);
        }
        std::string result = "";
        if (num == 0)
            return result;
        int div = 10;
        while (num > 0)
        {
            int remainder = num % div;
        }
        return result;
    }
};

int main()
{
    int num = 79; // LXXIX
    Solution sol;
    std::cout << sol.intToRoman(num);
    return 0;
}
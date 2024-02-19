#include <iostream>
#include <bitset>

class Solution
{
public:
    bool isPowerOf2(int num)
    {
        int count = 0;
        std::bitset<32> bin(num);
        std::cout << bin;
        for (int i = 0; i < 32; i++)
        {
            if (bin[i] == 1)
                count++;
        }

        return count == 1;
    }
};

int main()
{
    Solution s;
    std::cout << s.isPowerOf2(-2147483648);
    return 0;
}
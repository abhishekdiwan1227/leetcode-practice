#include <iostream>
#include <unordered_set>
#include <vector>

class Solution
{
private:
    std::string validIpV4 = "0123456789";
    std::string validIpV6 = "0123456789abcdefABCDEF";
    std::unordered_set<char> ipV4set;
    std::unordered_set<char> ipV6set;

    std::vector<std::string> split(std::string s, char delimiter)
    {
        std::vector<std::string> res;
        for (int i = 0; i < s.length(); i++)
        {
            
        }
    }

    bool isValidIpV4(std::string ip)
    {
        if (ip.empty() || ip == "")
            return false;
    }

    bool isValidIpV6(std::string ip)
    {
    }

public:
    Solution() : ipV4set(validIpV4.cbegin(), validIpV4.cend()), ipV6set(validIpV6.cbegin(), validIpV6.cend()) {}

    std::string validIp(std::string ip)
    {
    }
};

int main()
{
    return 0;
}
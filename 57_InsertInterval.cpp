#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>> &intervals, std::vector<int> &newInterval)
    {
        std::vector<std::vector<int>> ans;
        int newStart = newInterval[0], newEnd = newInterval[1];
        if (intervals.size() == 0)
        {
            ans.push_back({newStart, newEnd});
        }
        else
        {
            std::vector<std::vector<int>>::const_iterator i = intervals.cbegin();
            while (i != intervals.cend())
            {
            }
        }

        return ans;
    }
};

int main()
{
    return 0;
}
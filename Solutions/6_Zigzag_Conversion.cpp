#include <iostream>
#include <vector>

class Solulu
{
public:
    int maxArea(std::vector<int> heights)
    {
        int maxArea = 0;
        int left = 0, right = heights.size() - 1;

        while (left < right)
        {
            int currHeight = std::min(heights[left], heights[right]);
            int currArea = currHeight * (right - left);
            maxArea = std::max(currArea, maxArea);

            if(heights[left] < heights[right]) left++;
            else if(heights[right] < heights[left]) right--;
            else 
            {
                left++;
                right--;
            }
        }

        return maxArea;
    }
};

int main()
{
    std::vector<int> heights{1, 8, 6, 2, 5, 4, 9, 3, 7};
    Solulu s;
    std::cout << s.maxArea(heights);
}
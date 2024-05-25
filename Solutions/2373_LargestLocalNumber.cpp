#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> largestLocal(std::vector<std::vector<int>> &grid)
    {
        int n = grid.size();
        int m = n - 2;

        std::vector<std::vector<int>> maxLocal = std::vector<std::vector<int>>(m, std::vector<int>(m));
        for (int i = 1, k = 0; i < n - 1; i++, k++)
        {
            for (int j = 1, l = 0; j < n - 1; j++, l++)
            {
                int m = findLocalLargest3x3(grid, i, j);
                std::cout << m << " ";
                maxLocal[k][l] = m;
            }
        }

        return maxLocal;
    }

private:
    int findLocalLargest3x3(std::vector<std::vector<int>> &grid, int i, int j)
    {
        int localMax = 0;

        std::vector<std::vector<int>> localGrid = {
            {i - 1, j - 1},
            {i - 1, j},
            {i - 1, j + 1},
            {i, j - 1},
            {i, j},
            {i, j + 1},
            {i + 1, j - 1},
            {i + 1, j},
            {i + 1, j + 1}};

        for (auto xy : localGrid)
        {
            int x = xy[0];
            int y = xy[1];

            localMax = std::max(localMax, grid[x][y]);
        }

        return localMax;
    }
};

int main()
{
    std::vector<std::vector<int>> grid = {{9, 9, 8, 1}, {5, 6, 2, 6}, {8, 2, 6, 4}, {6, 2, 2, 2}};

    Solution s;
    s.largestLocal(grid);
    return 0;
}
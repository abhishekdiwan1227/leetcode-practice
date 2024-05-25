#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>

class Solution
{
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>> pre)
    {
        initAdjMatrix(pre);
        for (int i = 0; i < numCourses; i++)
        {
            std::unordered_set<int> visited;
        }

        return true;
    }

private:
    std::map<int, std::unordered_set<int>> adjMatrix;

    void initAdjMatrix(std::vector<std::vector<int>> pre)
    {
        for (int i = 0; i < pre.size(); i++)
        {
            int course = pre[i][0];
            int preCourse = pre[i][1];
            if (adjMatrix.find(course) != adjMatrix.end())
            {
                adjMatrix[course].insert(preCourse);
            }
            else
            {
                adjMatrix[course] = std::unordered_set<int>{preCourse};
            }
        }
    }
};

int main()
{
    int numCourses = 4;
    std::vector<std::vector<int>> pre{{0, 1}, {0, 2}, {2, 1}, {1, 3}};
    Solution sol = Solution();
    sol.canFinish(numCourses, pre);
    return 0;
}
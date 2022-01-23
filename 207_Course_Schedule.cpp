#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        map<int, vector<int>> graph;
        unordered_set<int> visited;
        makeGraph(graph);
    }

private:
    void makeGraph(vector<vector<int>> &prerequisites, map<int, vector<int>> &graph)
    {
        for (vector<int> item : prerequisites)
        {
            if ()
            {
                graph[item[0]] = 
            }
        }
    }
};

int main()
{
    int numCourses = 2;
    vector<vector<int>> pre{{0, 1}, {1, 0}};
    Solution sol = Solution();
    cout << sol.canFinish(numCourses, pre);
    return 0;
}
#include <iostream>
#include <map>
#include <unordered_set>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(), right() {}
    TreeNode(int val) : val(val), left(), right() {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};

struct GraphNode
{
    int val;
    GraphNode *adj[];

    GraphNode() : val(0) {}
    GraphNode(int val) : val(val) {}
};

class Graph
{
private:
    std::queue<TreeNode *> traversal;

    void processTreeNode(TreeNode *current, TreeNode *parent)
    {
        if (parent != NULL)
            adj[current->val].insert(parent);
        if (current->left != NULL)
            adj[current->val].insert(current->left);
        if (current->right != NULL)
            adj[current->val].insert(current->right);
    }

    void traverse_tree(TreeNode *root, TreeNode *parent = NULL)
    {
        processTreeNode(root, parent);
        parent = root;
        if (root->left != NULL)
        {
            traverse_tree(root->left, parent);
        }
        if (root->right != NULL)
        {
            traverse_tree(root->right, parent);
        }
    }

public:
    std::map<int, std::unordered_set<TreeNode *>> adj;

    Graph(TreeNode *root)
    {
        if (root == NULL)
            return;
        traverse_tree(root);
    }

    void print()
    {
        for (auto i = adj.cbegin(); i != adj.cend(); i++)
        {
            std::cout << i->first << ": ";
            std::unordered_set<TreeNode *> adjNodes = i->second;
            std::cout << "[";
            for (auto j = adjNodes.cbegin(); j != adjNodes.cend(); j++)
            {
                TreeNode *adjNode = *j;
                if (adjNode != NULL)
                    std::cout << adjNode->val << ",";
            }
            std::cout << "]\n";
        }
    }
};

class Solution
{
private:
    void traversal(int current, std::map<int, std::unordered_set<TreeNode *>> *map, int &totalTime)
    {
        std::unordered_set adj = (*map)[current];
        for (auto i = adj.cbegin(); i != adj.cend(); i++)
        {
            TreeNode *node = *i;
            traversal(node->val, map, totalTime);
        }
        totalTime++;
    }

public:
    int amountOfTime(TreeNode *root, int start)
    {
        int totalTime = 0;

        Graph g(root);
        g.print();
        std::queue<std::unordered_set<int>> traversal;
        std::unordered_set<int> infected;
        traversal.push({start});
        while (!traversal.empty())
        {
            std::unordered_set<int> curr = traversal.front();
            traversal.pop();
            for (auto i = curr.cbegin(); i != curr.cend(); i++)
            {
                int currentNode = *i;
                infected.insert(currentNode);
                if (!g.adj[currentNode].empty())
                {
                    auto next = g.adj[currentNode];
                    std::unordered_set<int> nextVals;
                    for (auto j = next.cbegin(); j != next.cend(); j++)
                    {
                        int value = (*j)->val;
                        if (infected.find(value) == infected.cend())
                            nextVals.insert(value);
                    }
                    if (!nextVals.empty())
                        traversal.push(nextVals);
                };
            }
            totalTime++;
        }

        return totalTime - 1;
    }
};

int main()
{
    TreeNode root(1, new TreeNode(5, NULL, new TreeNode(4, new TreeNode(9), new TreeNode(2))), new TreeNode(3, new TreeNode(10), new TreeNode(6)));

    Solution s;
    std::cout << s.amountOfTime(&root, 3);
    return 0;
}
#include <iostream>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), right(nullptr), left(nullptr) {}
    TreeNode(int x) : val(x), right(nullptr), left(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), right(right), left(left) {}
};

class Solution
{
public:
    int findBottomLeftValue(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        std::queue<std::pair<TreeNode *, int>> levels;
        levels.push(std::make_pair(root, 0));
        std::pair<int, int> ans = std::make_pair(root->val, 0);

        while (!levels.empty())
        {
            auto curr = levels.front();
            TreeNode *node = curr.first;
            int level = curr.second;
            levels.pop();

            if (node->left)
            {
                levels.push(std::make_pair(node->left, level + 1));
                if (ans.second <= level)
                {
                    ans.first = node->left->val;
                    ans.second = level + 1;
                }
            }

            if (node->right)
            {
                levels.push(std::make_pair(node->right, level + 1));
            }
        }

        return ans.first;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(4), nullptr), new TreeNode(3, new TreeNode(5, new TreeNode(7), nullptr), new TreeNode(6)));

    Solution s;
    s.findBottomLeftValue(root);
    return 0;
}
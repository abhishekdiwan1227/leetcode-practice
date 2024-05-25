#include <iostream>

#define FALSE 0
#define TRUE 1
#define AND 2
#define OR 3

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool evaluateTree(TreeNode *root)
    {
        if (root->val == 1)
            return true;
        if (root->val == 0)
            return false;
        auto left = evaluateTree(root->left);
        auto right = evaluateTree(root->right);

        if (root->val == AND)
            return left && right;
        if (root->val == OR)
            return left || right;
    }
};

int main()
{
    Solution s;
    TreeNode root(OR, new TreeNode(TRUE), new TreeNode(FALSE));
    s.evaluateTree(&root);
    return 0;
}
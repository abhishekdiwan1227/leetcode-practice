#include <iostream>

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
    int distributeCoins(TreeNode *root)
    {
        if (root == NULL)
            return 0;
    }

    void process(TreeNode *node, int level, int rem)
    {
        if (node->val == 1)
            return;
        if (node->val > 1)
        {
            int toGive = node->val - 1;
            node->val = 1;
            rem += toGive;
        }
        if(node->val < 1)
        {
            
        }
    }
};

int main()
{
    return 0;
}
#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr){};
    ListNode(int val) : val(val), next(nullptr){};
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

class Solution
{
public:
    ListNode *nthNodeFromEnd(ListNode *root, int n)
    {
        if (root == NULL)
            return root;

        ListNode *i = root, *j = root;

        for (int i = 0; i < n && j; i++)
        {
            j = j->next;
        }

        ListNode *prev;

        while (j)
        {
            prev = i;
            i = i->next;
            j = j->next;
        }

        if (prev != i)
        {
            prev->next = i->next;
        }
        else
        {
            return NULL;
        }

        return root;
    }
};

int main()
{
    // ListNode root = ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    ListNode root;

    Solution s;
    ListNode *ans = s.nthNodeFromEnd(&root, 1);

    while (ans)
    {
        std::cout << ans->val;
        ans = ans->next;
        std::cout << "\t";
    }

    return 0;
}
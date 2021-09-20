#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        map<Node *, Node *> copyMap;
        traverseAndCopy(node, copyMap);
        attachNeighbors(copyMap);
        auto a = copyMap[node];
        return a;
    }

private:
    void traverseAndCopy(Node *root, map<Node *, Node *> &copyMap)
    {
        if (copyMap[root])
        {
            return;
        }
        else
        {
            Node *copyNode = new Node(root->val);
            copyMap[root] = copyNode;
            for (Node *neighbor : root->neighbors)
            {
                traverseAndCopy(neighbor, copyMap);
            }
        }
    }

    void attachNeighbors(map<Node *, Node *> &copyMap)
    {
        for (pair<Node *, Node *> item : copyMap)
        {
            Node *copyNode = item.second;
            for (Node *neighbor : item.first->neighbors)
            {
                copyNode->neighbors.push_back(copyMap[neighbor]);
            }
        }
    }
};

int main()
{
    Solution *sol = new Solution();
    Node *root = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    root->neighbors = vector<Node *>{n2, n4};
    n2->neighbors = vector<Node *>{root, n3};
    n3->neighbors = vector<Node *>{n2, n4};
    n4->neighbors = vector<Node *>{root, n2};

    sol->cloneGraph(root);

    return 0;
}
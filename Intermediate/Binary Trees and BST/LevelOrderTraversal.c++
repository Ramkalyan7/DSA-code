#include <bits/stdc++.h>
using namespace std;

// LC : https://leetcode.com/problems/binary-tree-level-order-traversal/description/
// soln : https://takeuforward.org/data-structure/level-order-traversal-of-a-binary-tree/

template <typename T>
class BinaryTreeNode
{
public:
    T val;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

void helper(BinaryTreeNode<int> *root, vector<int> &ans)
{
    queue<BinaryTreeNode<int> *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        ans.push_back(q.front()->val);
        if (q.front()->left)
        {
            q.push(q.front()->left);
        }
        if (q.front()->right)
        {
            q.push(q.front()->right);
        }
        q.pop();
    }
}

vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    vector<int> ans;
    helper(root, ans);
    return ans;
}
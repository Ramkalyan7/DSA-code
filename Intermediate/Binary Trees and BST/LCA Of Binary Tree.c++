#include <bits/stdc++.h>
using namespace std;

// LC :https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
// CS :https://www.codingninjas.com/studio/problems/920541
// sol :https://takeuforward.org/data-structure/lowest-common-ancestor-for-two-given-nodes/
// YT :https://www.youtube.com/watch?v=_-QHfMDde90

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode<int> *helper(TreeNode<int> *root, int x, int y)
{

    if (root == NULL || root->data == x || root->data == y)
    {
        return root;
    }

    TreeNode<int> *left = helper(root->left, x, y);
    TreeNode<int> *right = helper(root->right, x, y);

    if (left == NULL)
        return right;
    if (right == NULL)
        return left;
    return root;
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    //    Write your code here
    TreeNode<int> *ans = helper(root, x, y);
    return ans->data;
}
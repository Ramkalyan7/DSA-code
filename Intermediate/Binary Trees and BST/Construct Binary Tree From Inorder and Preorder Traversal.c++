#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
https://www.codingninjas.com/studio/problems/920539?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0
https://takeuforward.org/data-structure/construct-a-binary-tree-from-inorder-and-preorder-traversal/

*/

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

TreeNode<int> *helper(vector<int> &inorder, int inStart, int inEnd,
                      vector<int> &preorder, int preStart, int preEnd, unordered_map<int, int> &m)
{

    if (inStart > inEnd || preStart > preEnd)
        return NULL;

    TreeNode<int> *root = new TreeNode<int>(preorder[preStart]);

    int inRoot = m[preorder[preStart]];

    int numsLeft = inRoot - inStart;

    root->left = helper(inorder, inStart, inRoot - 1, preorder, preStart + 1, preStart + numsLeft, m);
    root->right = helper(inorder, inRoot + 1, inEnd, preorder, preStart + numsLeft + 1, preEnd, m);
    return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    //    Write your code here
    unordered_map<int, int> m;

    for (int i = 0; i < inorder.size(); i++)
    {
        m[inorder[i]] = i;
    }

    TreeNode<int> *root = helper(inorder, 0, inorder.size() - 1, preorder, 0, preorder.size() - 1, m);
    return root;
}
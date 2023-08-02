#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/boundary-traversal_790725?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0

// https://takeuforward.org/data-structure/boundary-traversal-of-a-binary-tree/

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

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

bool isLeaf(TreeNode<int> *node)
{
    return !node->left && !node->right;
}

void addLeftBoundary(TreeNode<int> *root, vector<int> &res)
{
    root = root->left;

    while (root)
    {
        if (!isLeaf(root))
            res.push_back(root->data);
        if (root->left)
            root = root->left;
        else
        {
            root = root->right;
        }
    }
}

void addLeaves(TreeNode<int> *root, vector<int> &res)
{

    if (root->left)
        addLeaves(root->left, res);
    if (isLeaf(root))
    {
        res.push_back(root->data);
    }

    if (root->right)
        addLeaves(root->right, res);
}

void addRightBoundary(TreeNode<int> *root, vector<int> &res)
{
    vector<int> temp;
    root = root->right;
    while (root)
    {
        if (!isLeaf(root))
            temp.push_back(root->data);
        if (root->right)
            root = root->right;
        else
        {
            root = root->left;
        }
    }

    for (int i = temp.size() - 1; i >= 0; --i)
    {
        res.push_back(temp[i]);
    }
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    // Write your code here.

    vector<int> res;
    if (!root)
        return res;
    if (isLeaf(root))
    {
        res.push_back(root->data);
        return res;
    }
    res.push_back(root->data);
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);
    return res;
}
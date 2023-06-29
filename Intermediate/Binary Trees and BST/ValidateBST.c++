#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/validate-binary-search-tree/

https://takeuforward.org/data-structure/check-if-binary-tree-is-bst/

https://www.codingninjas.com/studio/problems/799483?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0

https://www.youtube.com/watch?v=f-sj7I5oXEI
*/

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

bool validateBSTHelper(BinaryTreeNode<int> *root, int low, int high)
{

    if (root == NULL)
        return true;
    if (root->data < low || root->data > high)
        return false;

    return validateBSTHelper(root->left, low, root->data) &&
           validateBSTHelper(root->right, root->data, high);
}

bool validateBST(BinaryTreeNode<int> *root)
{
    // Write your code here
    int low = INT_MIN;
    int high = INT_MAX;
    if (root == NULL)
        return true;

    return validateBSTHelper(root, low, high);
}
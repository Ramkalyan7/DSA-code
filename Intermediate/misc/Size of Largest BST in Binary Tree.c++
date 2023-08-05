#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/893103?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0

// https://www.youtube.com/watch?v=X0oXMdtUDwo

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

class Node
{

public:
    int maxValue;
    int minValue;
    int size;

    Node(int maxValue, int minValue, int size)
    {
        this->maxValue = maxValue;
        this->minValue = minValue;
        this->size = size;
    }
};

Node largestBstHelper(TreeNode<int> *root)
{

    if (!root)
    {
        return Node(INT_MIN, INT_MAX, 0);
    }

    auto left = largestBstHelper(root->left);
    auto right = largestBstHelper(root->right);

    if (left.maxValue < root->data && root->data < right.minValue)
    {
        return Node(max(root->data, right.maxValue), min(root->data, left.minValue), left.size + right.size + 1);
    }

    return Node(INT_MAX, INT_MIN, max(right.size, left.size));
}

int largestBST(TreeNode<int> *root)
{
    // Write your code here.
    return largestBstHelper(root).size;
}

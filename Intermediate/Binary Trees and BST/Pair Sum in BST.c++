#include <bits/stdc++.h>
using namespace std;

/*
https://www.codingninjas.com/studio/problems/920493?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0

https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

https://www.youtube.com/watch?v=ssL3sHwPeb4


*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator
{
private:
    stack<TreeNode *> myStack;
    bool isReverse = true;

public:
    BSTIterator(TreeNode *root, bool reverse)
    {
        isReverse = reverse;
        pushAll(root);
    }

    int next()
    {
        TreeNode *temp = myStack.top();
        myStack.pop();
        if (!isReverse)
            pushAll(temp->right);
        else
            pushAll(temp->left);
        return temp->val;
    }

    bool hasNext()
    {
        return !myStack.empty();
    }

private:
    void pushAll(TreeNode *node)
    {
        while (node != NULL)
        {
            if (isReverse)
            {
                myStack.push(node);
                node = node->right;
            }
            else
            {
                myStack.push(node);
                node = node->left;
            }
        }
    }
};

class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        if (!root)
            return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        int i = l.next();
        int j = r.next();

        while (i < j)
        {
            if (i + j == k)
                return true;
            else if (i + j > k)
            {
                j = r.next();
            }
            else
            {
                i = l.next();
            }
        }

        return false;
    }
};

#include <bits/stdc++.h>
using namespace std;

/*
https://www.codingninjas.com/studio/problems/920519?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0
https://leetcode.com/problems/binary-tree-right-side-view/
https://takeuforward.org/data-structure/right-left-view-of-binary-tree/
*/

#include <bits/stdc++.h>

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

void helper(int level, TreeNode<int> *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (level == ans.size())
        ans.push_back(root->data);
    helper(level + 1, root->left, ans);
    helper(level + 1, root->right, ans);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> ans;
    helper(0, root, ans);
    return ans;
}
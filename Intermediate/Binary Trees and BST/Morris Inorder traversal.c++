#include <bits/stdc++.h>
using namespace std;

/*
https://takeuforward.org/data-structure/morris-inorder-traversal-of-a-binary-tree/
*/

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;

    TreeNode *cur = root;
    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            ans.push_back(cur->data);
            cur = cur->right;
        }
        else
        {
            TreeNode *temp = cur->left;
            while (temp->right && temp->right != cur)
            {
                temp = temp->right;
            }

            if (temp->right == NULL)
            {
                temp->right = cur;
                cur = cur->left;
            }
            else
            {
                ans.push_back(cur->data);
                temp->right = NULL;
                cur = cur->right;
            }
        }
    }

    return ans;
}
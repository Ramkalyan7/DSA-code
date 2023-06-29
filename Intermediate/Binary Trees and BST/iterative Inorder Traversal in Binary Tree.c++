#include <bits/stdc++.h>
using namespace std;

/*

https://www.youtube.com/watch?v=lxTGsVXjwvM
https://www.codingninjas.com/studio/problems/inorder-traversal_3839605?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0
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
    if (!root)
        return ans;
    stack<TreeNode *> st;
    TreeNode *node = root;
    while (true)
    {
        if (node != NULL)
        {

            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty())
                return ans;
            node = st.top();
            st.pop();

            ans.push_back(node->data);
            node = node->right;
        }
    }
    return ans;
}

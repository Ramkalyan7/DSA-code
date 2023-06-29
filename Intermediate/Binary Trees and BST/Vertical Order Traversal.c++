#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
https://takeuforward.org/data-structure/vertical-order-traversal-of-binary-tree/
https://www.codingninjas.com/studio/problems/vertical-order-traversal_920533?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0
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

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {

        queue<pair<TreeNode *, pair<int, int>>> q;

        map<int, map<int, multiset<int>>> m;

        q.push({root, {0, 0}});

        while (!q.empty())
        {

            auto p = q.front();
            q.pop();
            TreeNode *temp = p.first;

            int x = p.second.first;
            int y = p.second.second;

            m[x][y].insert(temp->val);

            if (temp->left)
            {
                q.push({temp->left,
                        {x - 1, y + 1}});
            }
            if (temp->right)
            {
                q.push({temp->right,
                        {x + 1, y + 1}});
            }
        }

        vector<vector<int>> ans;

        for (auto p : m)
        {
            vector<int> col;
            for (auto q : p.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};
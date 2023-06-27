#include <bits/stdc++.h>
using namespace std;

// there are two versions for this question

// soln for both the versions : https://takeuforward.org/data-structure/next-greater-element-using-stack/

// YT link for both the versions : https://www.youtube.com/watch?v=Du881K7Jtk8&t=1309s

// version 1 : not considering array circularly

// version 1 Question link of code studio : https://www.codingninjas.com/studio/problems/799354?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0

// code :

vector<int> nextGreater(vector<int> &arr, int n)
{
    // Write your code here
    vector<int> ans(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i])
            st.pop();

        if (st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top();
        st.push(arr[i]);
    }

    return ans;
}

// version 2 :  considering array circularly

// version 2  Question link of leet code : https://leetcode.com/problems/next-greater-element-ii/description/

// code :

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums[i % n])
            {
                st.pop();
            }

            if (i < n)
            {
                if (st.empty())
                    ans[i] = -1;
                else
                    ans[i] = st.top();
            }

            st.push(nums[i % n]);
        }

        return ans;
    }
};

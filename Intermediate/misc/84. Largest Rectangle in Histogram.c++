#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/largest-rectangle-in-histogram/description/
// https://takeuforward.org/data-structure/area-of-largest-rectangle-in-histogram/
// https://www.codingninjas.com/studio/problems/1058184?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        // find left smaller elements
        // find right smaller elements
        // find max area

        int n = heights.size();
        stack<int> st;
        int leftsmall[n], rightsmall[n];

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if (st.empty())
                leftsmall[i] = 0;
            else
                leftsmall[i] = st.top() + 1;
            st.push(i);
        }

        // clear the stack to be re-used
        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (st.empty())
                rightsmall[i] = n - 1;
            else
                rightsmall[i] = st.top() - 1;

            st.push(i);
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            ans = max(ans, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
        }

        return ans;
    }
};
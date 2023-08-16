#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/sliding-maximum_701652?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0

// https://leetcode.com/problems/sliding-window-maximum/

// https://takeuforward.org/data-structure/sliding-window-maximum/

vector<int> maxSlidingWindow(vector<int> &arr, int n, int k)
{
    // Write your code here.
    vector<int> ans;

    deque<int> dq;

    for (int i = 0; i < arr.size(); i++)
    {
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();

        while (!dq.empty() && arr[dq.back()] < arr[i])
            dq.pop_back();

        dq.push_back(i);

        if (i >= k - 1)
            ans.push_back(arr[dq.front()]);
    }

    return ans;
}
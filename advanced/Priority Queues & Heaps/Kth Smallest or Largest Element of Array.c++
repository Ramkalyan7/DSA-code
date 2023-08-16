#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/kth-smallest-and-largest-element-of-array_1115488?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0

// https://www.youtube.com/watch?v=hW8PrQrvMNc&list=PL_z_8CaSLPWdtY9W22VjnPxG30CXNZpI9&index=1&pp=iAQB ------>important video

// https://www.youtube.com/watch?v=4BfL2Hjvh8g&list=PL_z_8CaSLPWdtY9W22VjnPxG30CXNZpI9&index=2&pp=iAQB

// https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/

vector<int> kthSmallLarge(vector<int> &nums, int n, int k)
{
    // Write your code here.

    /// kth smallest
    priority_queue<int> maxHeap;

    for (int i = 0; i < nums.size(); i++)
    {
        maxHeap.push(nums[i]);
        if (maxHeap.size() > k)
        {
            maxHeap.pop();
        }
    }

    vector<int> ans;
    ans.push_back(maxHeap.top());

    /// kth largest

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < nums.size(); i++)
    {
        minHeap.push(nums[i]);
        if (minHeap.size() > k)
        {
            minHeap.pop();
        }
    }

    ans.push_back(minHeap.top());

    return ans;
}
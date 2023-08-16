#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/running-median_625409?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0

// https://www.youtube.com/watch?v=EcNbRjEcb14&t=557s

void findMedian(int *arr, int n)
{
    // Write your code here

    priority_queue<int> maxHeap;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; i++)
    {
        if (maxHeap.empty() || maxHeap.top() > arr[i])
        {
            maxHeap.push(arr[i]);
        }

        else
            minHeap.push(arr[i]);

        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        else if (minHeap.size() > maxHeap.size() + 1)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        if (maxHeap.size() == minHeap.size())
        {
            cout << (maxHeap.top() + minHeap.top()) / 2 << " ";
        }

        else if (maxHeap.size() > minHeap.size())
        {
            cout << maxHeap.top() << " ";
        }
        else
        {
            cout << minHeap.top() << " ";
        }
    }
}
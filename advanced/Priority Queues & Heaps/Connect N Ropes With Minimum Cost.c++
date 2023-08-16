#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/connect-n-ropes-with-minimum-cost_630476?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0

// https://www.youtube.com/watch?v=_k_c9nqzKN0

/*
    Time Complexity : O(N * log(N))
    Space Complexity : O(N)

    where N is the number of ropes given initially
*/

int connectRopes(int *arr, int n)
{
    // Initialize final cost variable
    int finalCost = 0;

    // Declaring a minHeap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Inserting all ropes to the minHeap
    for (int i = 0; i < n; i++)
    {
        minHeap.push(arr[i]);
    }

    // Merge until there is only one rope left in minHeap
    while (minHeap.size() > 1)
    {
        // Extract the smallest rope
        int smallest = minHeap.top();
        minHeap.pop();

        // Extract the second smallest rope
        int secondSmallest = minHeap.top();
        minHeap.pop();

        // Add cost of merging these two ropes to final answer
        finalCost += (smallest + secondSmallest);

        // Insert the combined rope back in the minHeap
        minHeap.push(smallest + secondSmallest);
    }

    // Return the finalCost
    return finalCost;
}

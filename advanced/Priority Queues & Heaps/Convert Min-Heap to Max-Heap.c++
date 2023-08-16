#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/convert-min-heap-to-max-heap_630293?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0

// love babbar or abdul bari  course

void heapify(long *arr, int i, int n)
{
    int left = i * 2 + 1, right = left + 1;
    if (left >= n)
        return;
    int large = (right < n && arr[right] > arr[left]) ? right : left;
    if (arr[large] > arr[i])
        swap(arr[large], arr[i]);
    heapify(arr, large, n);
}

void minHeapToMaxHeap(long *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, i, n);
    }
}
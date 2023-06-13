#include <bits/stdc++.h>
using namespace std;

// leetcode and code studio

// solution and explanation  can be found at take you forward
// https://takeuforward.org/data-structure/move-all-zeros-to-the-end-of-the-array/

void pushZerosAtEnd(vector<int> &arr)
{
    // Write your code here.

    int n = arr.size();

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            count++;
        }
    }

    int i = 0;
    int j = 0;
    while (i < n)
    {
        if (arr[i] != 0)
        {
            arr[j] = arr[i];
            j++;
        }
        i++;
    }

    i = n - count;
    while (i < n)
    {
        arr[i] = 0;
        i++;
    }
}
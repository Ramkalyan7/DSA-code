#include <bits/stdc++.h>
using namespace std;

/*
    Time complexity: O(N)
    Space complexity: O(1)

    Where 'N' is the total number of elements in the array.
*/

int findSecondLargest(int n, vector<int> &arr)
{
    int largest = INT_MIN, secondLargest = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        // Find largest and second largest element simultaneously.
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }

        // If an element is smaller than largest and smaller than second largest.
        else if (arr[i] > secondLargest && arr[i] != largest)
        {
            secondLargest = arr[i];
        }
    }

    if (secondLargest != INT_MIN)
    {
        return secondLargest;
    }
    else
    {
        return -1;
    }
}

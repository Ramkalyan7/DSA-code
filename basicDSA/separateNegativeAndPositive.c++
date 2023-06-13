
#include <bits/stdc++.h>
using namespace std;

vector<int> separateNegativeAndPositive(vector<int> &arr)
{
    // Write your code here.
    int i = 0;
    int n = arr.size();
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            if (i != j)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            j++;
        }
    }
    return arr;
}
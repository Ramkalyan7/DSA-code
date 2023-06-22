#include <bits/stdc++.h>
using namespace std;

void inplaceRotate(vector<vector<int>> &arr)
{
    // Write your code here.
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    int col = 0;
    while (col < n)
    {
        int s = 0;
        int e = n - 1;
        while (s < e)
        {
            swap(arr[e][col], arr[s][col]);
            s++;
            e--;
        }
        col++;
    }
}
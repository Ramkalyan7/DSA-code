#include <bits/stdc++.h>
using namespace std;
void rotaterow(vector<int> &arr)
{
    int n = arr.size();
    int insert = arr[n - 1];
    for (int i = n - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = insert;
}
vector<int> rotateMatRight(vector<vector<int>> mat, int n, int m, int k)
{
    int rotate = k % m;
    while (rotate--)
    {
        for (int i = 0; i < n; i++)
        {
            rotaterow(mat[i]);
        }
    }
    vector<int> x;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            x.push_back(mat[i][j]);
        }
    }
    return x;
}
#include <bits/stdc++.h>
using namespace std;
int findEquilibriumIndex(vector<int> &arr)
{
    int n = arr.size();

    int LeftSum = 0;
    int RightSum = 0;
    for (int i = 1; i < n; i++)
    {
        RightSum += arr[i];
    }
    for (int i = 0; i < n; i++)
    {

        if (LeftSum == RightSum)
            return i;
        LeftSum += arr[i];
        RightSum -= arr[i + 1];
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 7, 3, 6, 5, 6};
    cout << findEquilibriumIndex(arr);
}
#include <bits/stdc++.h>
using namespace std;

int areAll9s(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 9)
            return 0;
    }
    return 1;
}

vector<int> generateNextSmallestPalindromeUtil(vector<int> arr, int n)
{

    int mid = n / 2;

    int i = mid - 1;

    bool leftSmaller = false;

    int j = n % 2 ? mid + 1 : mid;

    while (i >= 0 && arr[i] == arr[j])
    {
        i--;
        j++;
    }

    if (i < 0 || arr[i] < arr[j])
    {
        leftSmaller = true;
    }

    while (i >= 0)
    {
        arr[j] = arr[i];
        i--;
        j++;
    }

    if (leftSmaller == true)
    {

        int carry = 1;
        i = mid - 1;
        if (n % 2 == 1)
        {
            arr[mid] += carry;
            carry = arr[mid] / 10;
            arr[mid] = arr[mid] % 10;
            j = mid + 1;
        }
        else
            j = mid;

        while (i >= 0)
        {
            arr[i] += carry;
            carry = arr[i] / 10;
            arr[i] = arr[i] % 10;
            arr[j] = arr[i];
            j++;
            i--;
        }
    }
    return arr;
}

vector<int> generateNextSmallestPalindrome(vector<int> arr, int n)
{

    vector<int> ans;

    if (areAll9s(arr, n))
    {
        ans.push_back(1);
        for (int i = 0; i < n - 1; i++)
        {
            ans.push_back(0);
        }
        ans.push_back(1);
    }

    // if not all are 9'arr
    else
    {

        ans = generateNextSmallestPalindromeUtil(arr, n);
    }

    return ans;
}

vector<int> nextLargestPalindrome(vector<int> arr, int n)
{

    vector<int> ans = generateNextSmallestPalindrome(arr, n);
    return ans;
}

int main()
{
    vector<int> arr = {3, 2, 9, 8, 9, 3, 4};

    vector<int> ans = generateNextSmallestPalindrome(arr, arr.size());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
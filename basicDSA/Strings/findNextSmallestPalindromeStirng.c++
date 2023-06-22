#include <bits/stdc++.h>
using namespace std;

int areAll9s(string arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != '9')
            return 0;
    }
    return 1;
}

string generateNextSmallestPalindromeUtil(string arr, int n)
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
            int num = arr[mid] - 48;

            num += carry;
            carry = num / 10;
            num = num % 10;
            j = mid + 1;
            arr[mid] = num + 48;
        }
        else
            j = mid;

        while (i >= 0)
        {
            int num = arr[i] - 48;
            num += carry;
            carry = num / 10;
            num = num % 10;
            arr[i] = num + 48;
            arr[j] = arr[i];
            j++;
            i--;
        }
    }
    return arr;
}

string generateNextSmallestPalindrome(string arr, int n)
{

    string ans;

    if (areAll9s(arr, n))
    {
        ans.push_back('1');
        for (int i = 0; i < n - 1; i++)
        {
            ans.push_back('0');
        }
        ans.push_back('1');
    }

    // if not all are 9'arr
    else
    {

        ans = generateNextSmallestPalindromeUtil(arr, n);
    }

    return ans;
}

string nextLargestPalindrome(string arr, int n)
{

    string ans = generateNextSmallestPalindrome(arr, n);
    return ans;
}

int main()
{
    string arr = "121";

    string ans = generateNextSmallestPalindrome(arr, arr.length());
    cout << ans << endl;
}
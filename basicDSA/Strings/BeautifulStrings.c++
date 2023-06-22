#include <bits/stdc++.h>
using namespace std;

int makeBeautiful(string str)
{
    // Write your code here

    char cur1 = '0';
    int ans1 = 0;
    if (str[0] != cur1)
        ans1++;
    int n = str.length();
    int ans2 = 0;
    char cur2 = '1';
    if (str[0] != cur2)
        ans2++;

    for (int i = 1; i < n; i++)
    {
        if (str[i] == cur1)
        {
            ans1++;
        }

        if (cur1 == '0')
            cur1 = '1';
        else
            cur1 = '0';

        if (str[i] == cur2)
        {
            ans2++;
        }

        if (cur2 == '0')
            cur2 = '1';
        else
            cur2 = '0';
    }

    return min(ans1, ans2);
}

int main()
{

    return 0;
}
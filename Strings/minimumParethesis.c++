#include <bits/stdc++.h>
#include <vector>
using namespace std;

int minimumParentheses(string pattern)
{
    // Write your code here.
    // pattern is the given string.

    int count = 0;
    int ans = 0;
    int n = pattern.length();
    for (int i = 0; i < n; i++)
    {
        if (count < 0)
        {
            ans += abs(count);
            count = 0;
        }
        if (pattern[i] == '(')
            count++;
        else if (pattern[i] == ')')
            count--;
    }
    if (count < 0)
        ans += abs(count);
    else
        ans += count;
    return ans;
}

int main()
{
    string p;
    getline(cin, p);
    cout << minimumParentheses(p);
}
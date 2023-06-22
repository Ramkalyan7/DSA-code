#include <bits/stdc++.h>
using namespace std;

// leetcode link : https://leetcode.com/problems/sqrtx/description/

// video solution link : https://www.youtube.com/watch?v=Bsv3FPUX_BA

class Solution
{
public:
    int mySqrt(int n)
    {
        int s = 0;
        if (n == 1)
            return 1;
        int e = n;
        long long mid = s + (e - s) / 2;

        long long ans = -1;
        while (s <= e)
        {

            long long square = mid * mid;

            if (square <= n)
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
        return ans;
    }
};
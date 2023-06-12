

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int ans = 0;
        int sum = 0;
        int remainder = 0;

        unordered_map<int, int> m;
        m[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            remainder = sum % k;
            if (remainder < 0)
            {
                remainder += k;
            }
            if (m.find(remainder) != m.end())
            {
                ans += m[remainder];

                m[remainder] = m[remainder] + 1;
            }
            else
            {
                m[remainder] = 1;
            }
        }

        return ans;
    }
};
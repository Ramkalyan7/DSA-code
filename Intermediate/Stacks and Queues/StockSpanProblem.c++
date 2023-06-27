#include <bits/stdc++.h>
using namespace std;

/*


It is a variation of problems next greater element , previous greater element !!


*/

// YT : https://www.youtube.com/watch?v=p9T-fE1g1pU

// CS : https://www.codingninjas.com/studio/problems/span-of-ninja-coin_1475049?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=2

// LC : https://leetcode.com/problems/online-stock-span/description/

// solution for code studio version of problem

/*

    Time Complexity : O(N)
    Space Complexity : O(N)

    where 'N' is the size of array/list ‘PRICE’.

*/

vector<int> findSpans(vector<int> &price)
{
    //  Size of array/list ‘price’.
    int n = price.size();

    vector<int> result(n);
    stack<int> stk;

    for (int i = 0; i < n; i++)
    {
        //  Stack will have only those days before ‘i’ in which price is higher than price at day ‘i’.
        while (stk.empty() == false && price[stk.top()] <= price[i])
        {
            stk.pop();
        }

        //  Span on day 'i'.
        if (stk.empty() == true)
        {
            result[i] = i + 1;
        }
        else
        {
            result[i] = i - stk.top();
        }

        stk.push(i);
    }

    return result;
}

// solution for leetcode version of problem

class StockSpanner
{
    stack<pair<int, int>> st;
    int index;

public:
    StockSpanner()
    {
        index = -1;
    }

    int next(int price)
    {
        int res;
        index++;

        if (st.empty())
            res = index + 1;

        while (!st.empty() && st.top().first <= price)
        {
            st.pop();
        }
        if (st.empty())
            res = index + 1;
        else
            res = index - st.top().second;

        st.push({price, index});

        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

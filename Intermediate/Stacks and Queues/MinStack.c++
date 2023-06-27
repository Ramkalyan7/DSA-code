#include <bits/stdc++.h>
using namespace std;

// LC : https://leetcode.com/problems/min-stack/description/

// sol : https://takeuforward.org/data-structure/implement-min-stack-o2n-and-on-space-complexity/

// YT : https://www.youtube.com/watch?v=V09NfaGf2ao

// better approach :

class MinStack
{
    stack<pair<int, int>> st;

public:
    void push(int x)
    {
        int min;
        if (st.empty())
        {
            min = x;
        }
        else
        {
            min = std::min(st.top().second, x);
        }
        st.push({x, min});
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};

// most optimised approach

class MinStack
{
    stack<long long> st;
    long long mini;

public:
    /** initialize your data structure here. */
    MinStack()
    {
        while (st.empty() == false)
            st.pop();
        mini = INT_MAX;
    }

    void push(int value)
    {
        long long val = value;
        if (st.empty())
        {
            mini = val;
            st.push(val);
        }
        else
        {
            if (val < mini)
            {
                st.push(2 * val * 1LL - mini);
                mini = val;
            }
            else
            {
                st.push(val);
            }
        }
    }

    void pop()
    {
        if (st.empty())
            return;
        long long el = st.top();
        st.pop();

        if (el < mini)
        {
            mini = 2 * mini - el;
        }
    }

    int top()
    {
        if (st.empty())
            return -1;

        long long el = st.top();
        if (el < mini)
            return mini;
        return el;
    }

    int getMin()
    {
        return mini;
    }
};

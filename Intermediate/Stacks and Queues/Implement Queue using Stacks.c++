#include <bits/stdc++.h>
using namespace std;

// LC : https://leetcode.com/problems/implement-queue-using-stacks/

// soln : https://takeuforward.org/data-structure/implement-queue-using-stack/

// look soln of code studio as well for solution

class MyQueue
{
    stack<int> stk1, stk2;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        stk1.push(x);
    }

    int pop()
    {
        int res = -1;
        if (stk1.empty() && stk2.empty())
            res = -1;

        else if (stk2.empty())
        {
            while (!stk1.empty())
            {
                stk2.push(stk1.top());
                stk1.pop();
            }
            res = stk2.top();
            stk2.pop();
        }
        else
        {
            res = stk2.top();
            stk2.pop();
        }

        return res;
    }

    int peek()
    {
        if (!stk2.empty())
            return stk2.top();
        else
        {
            while (!stk1.empty())
            {
                stk2.push(stk1.top());
                stk1.pop();
            }
            return stk2.top();
        }
    }

    bool empty()
    {
        return stk1.empty() && stk2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
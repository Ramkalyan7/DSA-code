#include <bits/stdc++.h>
using namespace std;

// LC : https://leetcode.com/problems/implement-stack-using-queues/

// soln : https://takeuforward.org/data-structure/implement-stack-using-single-queue/

// look soln of code studio as well for solution

class MyStack
{
    queue<int> q1, q2;

public:
    MyStack()
    {
    }

    int getSize()
    {
        // Implement the getSize() function.
        return q1.size() + q2.size();
    }

    void push(int element)
    {
        if (q2.empty())
            q1.push(element);
        else if (q1.empty())
            q2.push(element);
    }

    int pop()
    {
        int res = -1;
        if (q1.empty())
            res = -1;

        else
        {
            while (!q1.empty())
            {

                res = q1.front();
                q1.pop();
                if (!q1.empty())
                    q2.push(res);
            }
        }
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;

        return res;
    }

    int top()
    {
        if (getSize())
        {
            if (q1.empty())
                return q2.back();
            else if (q2.empty())
                return q1.back();
        }
        return -1;
    }

    bool empty()
    {
        // Implement the isEmpty() function.
        if (q1.empty() && q2.empty())
            return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
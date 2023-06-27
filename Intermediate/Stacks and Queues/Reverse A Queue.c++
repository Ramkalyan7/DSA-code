#include <bits/stdc++.h>
using namespace std;

// CS : https://www.codingninjas.com/studio/problems/reversing-a-queue_982934

// soln link : https://takeuforward.org/data-structure/reversing-a-queue/

// iterative soln code :
#include <bits/stdc++.h>
queue<int> reverseQueue(queue<int> q)
{
    // Write your code here.
    stack<int> st;

    while (!q.empty())
    {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    return q;
}

// using recursion :

void reverseQueueHelper(queue<int> &q)
{

    if (q.empty())
    {
        return;
    }

    int n = q.front();
    q.pop();
    reverseQueueHelper(q);
    q.push(n);
}

queue<int> reverseQueue(queue<int> q)
{
    // Write your code here.

    reverseQueueHelper(q);
    return q;
}

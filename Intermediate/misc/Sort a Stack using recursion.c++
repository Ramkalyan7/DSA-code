#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=MOGBRkkOhkY

// https://www.youtube.com/watch?v=AZ4jEY_JAVc

// https://www.codingninjas.com/studio/problems/sort-a-stack_985275?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0

void insertStack(stack<int> &stack, int temp)
{

    if (stack.size() == 0 || stack.top() <= temp)
    {
        stack.push(temp);
        return;
    }

    int val = stack.top();
    stack.pop();
    insertStack(stack, temp);
    stack.push(val);
    return;
}

void sortStack(stack<int> &stack)
{
    // Write your code here

    if (stack.size() == 1)
        return;

    int temp = stack.top();
    stack.pop();
    sortStack(stack);
    insertStack(stack, temp);
    return;
}
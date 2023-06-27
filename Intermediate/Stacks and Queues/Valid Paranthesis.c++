#include <bits/stdc++.h>
using namespace std;

// CS : https://www.codingninjas.com/studio/problems/valid-parenthesis_795104

// LC : https://leetcode.com/problems/valid-parentheses/

// YT : https://www.youtube.com/watch?v=wkDfsKijrZ8

// sol : https://takeuforward.org/data-structure/check-for-balanced-parentheses/

// code :

bool isClosingParenthesis(char c) { return c == ']' || c == '}' || c == ')'; }

bool isValid(char c1, char c2)
{
    if ((c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}') ||
        (c1 == '(' && c2 == ')'))
    {
        return true;
    }
    return false;
}

bool isValidParenthesis(string expression)
{
    // Write your code here.

    int n = expression.length();
    stack<char> st;

    for (int i = 0; i < n; i++)
    {
        if (!isClosingParenthesis(expression[i]))
        {
            st.push(expression[i]);
        }
        else
        {

            if (!st.empty() && isValid(st.top(), expression[i]))
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }

    return st.empty();
}
#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/implement-a-priority-queue-using-heap-and-also-implement-getmaxelement-in-the-queue_1743878?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube

// love babbar or abdul bari  course

int pop(vector<int> &heap)
{
    int n = heap.size();
    if (n == 0)
        return -1;

    int res = heap[0];

    heap[0] = heap[n - 1];
    heap.pop_back();
    n--;

    int i = 0;

    while (true)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && heap[left] > heap[i] && (right >= n || heap[left] >= heap[right]))
        {
            swap(heap[left], heap[i]);
            i = left;
        }
        else if (right < n && heap[right] > heap[i])
        {
            swap(heap[right], heap[i]);
            i = right;
        }
        else
        {
            break;
        }
    }

    return res;
}

// Code Snippet of the push function:
//
//     void push(vector<int> &heap, int x)
//     {
//           heap.push_back(x);
//
//            // Posistion of the current inserted element.
//            int pos=heap.size()-1;
//
//            // Shifting the element up until it reaches the top most node if it is larger than its parent.
//            while(pos>0)
//            {
//                int parent = (pos-1)/2;
//                if(heap[pos] > heap[parent])
//                {
//                    swap(heap[parent],heap[pos]);
//                    pos=parent;
//               }
//              else
//              {
//                  // As parent is larger the element now is in its correct position.
//                  break;
//              }
//          }
//      }

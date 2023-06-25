#include <bits/stdc++.h>
using namespace std;

// LC:https://leetcode.com/problems/middle-of-the-linked-list/submissions/977583757/
// SL:https://takeuforward.org/data-structure/find-middle-element-in-a-linked-list/

// Node *findMiddle(Node *head) {
//     // Write your code here
//     Node *fast=head;
//     Node *slow=head;
//     while(fast!=NULL && fast->next!=NULL){
//          slow=slow->next;
//         fast=fast->next->next;
//     }

//     return slow;
// }
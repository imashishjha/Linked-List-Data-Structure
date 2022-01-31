
// You are given the head of a linked list with n nodes.

// For each node in the list, find the value of the next greater node. 
// That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

// Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). 
// If the ith node does not have a next greater node, set answer[i] = 0
#include <bits/stdc++.h>

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans1;
        vector<int> ans;
        
        if(head->next == NULL){
            ans1.push_back(0);
            return ans1;
        }
        
      ListNode* p = head;
      ListNode* q= head->next;
        
    int nextmax=0;
      
 while(p->next != NULL){
    while(q != NULL){
        nextmax = max(nextmax, q->val);
        q=q->next;
    }
      q= p->next;
        
      if(p->val >= nextmax){
          ans.push_back(0);
      }else{
          ans.push_back(nextmax);
      }
     
     p= q;
     
     q= q->next;
     
     nextmax=0;
 }  
      ans.push_back(0);
      return ans;  
    }
};
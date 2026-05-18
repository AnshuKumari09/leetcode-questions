/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // check first if there is cycle in the linked list
        // slow and fast pointer
        if(!head || head->next==NULL || head->next->next==NULL){
            return NULL;
        }
        ListNode* slow=head;
        ListNode* fast=head;
         ListNode* p=head;
       
        
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
            
                if(fast==slow){
                    // cycle detected
                    while(slow!=p){
            slow=slow->next;
            p=p->next;
        }
        return p;
                }
            
        }
       return NULL;
        
    }
};
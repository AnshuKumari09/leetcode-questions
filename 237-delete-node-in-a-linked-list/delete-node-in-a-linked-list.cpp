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
    void deleteNode(ListNode* node) {
        // let the node to be deleted be curr node
        // then we have to do prev-> next=curr->next , curr->next =NULL

        // method 2
        // curr=node
        // prev=node
          ListNode* curr = node;
        ListNode* prev = node;
        while(curr->next){
            curr=curr->next;
            prev->val=curr->val;
            if(curr->next){
                  prev=curr;
            }
           
        }
        
prev->next=NULL;
delete(curr);
        
    }
};
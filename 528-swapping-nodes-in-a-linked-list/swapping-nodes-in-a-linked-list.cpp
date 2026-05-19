/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* temp1=head;
       
        ListNode* temp2=head;
        // count the length
        int n=0;
        while(temp){
              n++;
              temp=temp->next;
        }
        
         int num1=0;
         int num2=0;

        for(int i=1;i<=n;i++){
            if(i==k){
              num1=temp1->val;
            }
            if(i==n-k+1){
                num2=temp1->val;
            }
            temp1=temp1->next;
        }
         for(int i=1;i<=n;i++){
            if(i==k){
                temp2->val=num2;
            }
            if(i==n-k+1){
                temp2->val=num1;
            }
            temp2=temp2->next;
        }
        return head;
    
    }
};
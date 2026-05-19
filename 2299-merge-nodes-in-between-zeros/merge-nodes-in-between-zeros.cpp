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
    ListNode* mergeNodes(ListNode* head) {
        // check if zero is present
        ListNode* temp=head->next;
        int sum=0;
        ListNode* dummy=new ListNode(0);

        ListNode* result=dummy;
        while(temp){
            if(temp->val==0){
              
                    ListNode* curr=new ListNode(sum);
                    result->next=curr;
                    result=result->next;
                    sum=0;

                               
            }
            else{
                sum+=(temp->val);
            }
            temp=temp->next;
        }
        return dummy->next;
    }
};
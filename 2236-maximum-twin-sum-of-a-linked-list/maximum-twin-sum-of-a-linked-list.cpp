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
    int pairSum(ListNode* head) {
        ListNode* temp=head;
        vector<int>res;
        while(temp){
            res.push_back(temp->val);
            temp=temp->next;
            
        }
        int i=0;
        int j=res.size()-1;
        int maxS=0;
       while(i<j){
          int sum=res[i]+res[j];
          maxS=max(maxS,sum);
          j--;
          i++;
       }
       return maxS;
    }
};
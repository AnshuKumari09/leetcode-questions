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
// class Solution {
// public:
//     int pairSum(ListNode* head) {
//         ListNode* temp=head;
//         vector<int>res;
//         while(temp){
//             res.push_back(temp->val);
//             temp=temp->next;
            
//         }
//         int i=0;
//         int j=res.size()-1;
//         int maxS=0;
//        while(i<j){
//           int sum=res[i]+res[j];
//           maxS=max(maxS,sum);
//           j--;
//           i++;
//        }
//        return maxS;
//     }
// };

// class Solution {
// public:
//     int pairSum(ListNode* head) {
//         ListNode* temp=head;
//         ListNode* temp1=head;
//         stack<int>res;
//         int n=0;

//         while(temp){
//             n++;
//             res.push(temp->val);
//             temp=temp->next;
            
//         }
//         int maxS=0;
//         for(int i=0;i<n/2;i++){
//             int sum=res.top()+temp1->val;
//             res.pop();
//             maxS=max(maxS,sum);
//             temp1=temp1->next;3
//         }
//      return maxS;
//     }
// };


class Solution {
public:
    int pairSum(ListNode* head) {
      // third approach 
    //   a-b-c-d-e-f
    //   a-b-c-f-e-d  -> mid pointer at f . okay ab kya akre
    //   pehle mujhe mid tk jana hoga . slow aur fats lga do
      ListNode* slow=head;
      ListNode* temp=head;
      ListNode* fast=head;
      while(fast && fast->next){
         slow=slow->next;
         fast=fast->next->next;
      }
    //   list mil gyi ab reverse krna h. 

      ListNode* mid=slow;
      ListNode* prev=NULL;
      ListNode* curr=slow;
      while(curr){
           ListNode* future=curr->next;
           curr->next=prev;
           prev=curr;
           curr=future;
      }

      //concatenate 
      int maxValue=0;
         while(prev){
            int value=prev->val + temp->val;
              maxValue=max(maxValue,value);
              prev=prev->next;
              temp=temp->next;
         }
       return maxValue;
    }
};
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

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* temp=head;
        ListNode* temp1=head;
        stack<int>res;
        int n=0;

        while(temp){
            n++;
            res.push(temp->val);
            temp=temp->next;
            
        }
        int maxS=0;
        for(int i=0;i<n/2;i++){
            int sum=res.top()+temp1->val;
            res.pop();
            maxS=max(maxS,sum);
            temp1=temp1->next;
        }
     return maxS;
    }
};
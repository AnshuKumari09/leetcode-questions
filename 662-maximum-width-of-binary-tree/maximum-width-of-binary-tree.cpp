/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        // level wise traverse krna hai .
        queue<pair<TreeNode*,long long>>que;
        long long maxWidth=0;
        que.push({root,0});
         // i har baar update hoga
         while(!que.empty()){
            int sz=que.size();
            pair<TreeNode*,long long>first=que.front();
             long long base = que.front().second;
               pair<TreeNode*,long long>last=que.back();
                long long currWidth=last.second-first.second+1;
                maxWidth=max(currWidth,maxWidth);
            while(sz--){
                pair<TreeNode*,long long>temp=que.front();
                que.pop();
                TreeNode* curr=temp.first;
                long long index=temp.second- base;
                
                if(curr->left){
                    que.push({curr->left,2*index+1});
                }
              
                if(curr->right){
                    que.push({curr->right,2*index+2});
                }
            }
         }
         return maxWidth;
    }
};
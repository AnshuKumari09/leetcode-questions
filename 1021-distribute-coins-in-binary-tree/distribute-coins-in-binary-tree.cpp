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
     
    int solve(TreeNode* root,int &moves){
          if(root==NULL){
            return 0;
          }

          int lec=solve(root->left,moves);
          int rec=solve(root->right,moves);
          moves+=abs(lec)+abs(rec);
          int tec=lec+rec+root->val-1;
          return tec;
     }
    int distributeCoins(TreeNode* root) {
        int moves=0;
        if(!root->left && !root->right){
            return 0;
        }
         solve(root,moves);
         return moves;
    }
};
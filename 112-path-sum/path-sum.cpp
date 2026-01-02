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
    bool sum=false;
     void checkTheSum(TreeNode* root, int targetSum,int currSum){
          if(root==NULL){
            return;
          }
          if(sum){
            return;
          }
          currSum+=root->val;
          if(!root->left && !root->right && currSum==targetSum){
            sum=true;
            return;
          }
          
          checkTheSum(root->left,targetSum,currSum);
          checkTheSum(root->right,targetSum,currSum);
     }
    bool hasPathSum(TreeNode* root, int targetSum) {

      checkTheSum(root,targetSum,0);
      if(sum==true){
        return true;
      }
      return false;
    }
};
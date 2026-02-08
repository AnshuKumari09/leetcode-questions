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
  int findHeight(TreeNode* root){
    if(!root){
        return 0;
    }

       return 1+max(findHeight(root->left),findHeight(root->right));
  }
   bool tryEveryNode(TreeNode* root){
       if(!root) return true;
       if(abs(findHeight(root->left)-findHeight(root->right))>1){
           return false;
       }
    //    if(root->left){
    //       return tryEveryNode(root->left);
    //    }
    //    if(root->right){
    //     return tryEveryNode(root->right);
    //    }
       return tryEveryNode(root->left) && tryEveryNode(root->right); 
   }
    bool isBalanced(TreeNode* root) {
       // (differnce of heights>1)
    //    if(root->left){
    //         findHeight(root->left);
    //    }
        if(!root){
            return true;
        }
       if(!tryEveryNode(root)){
        return false;
       }
       return true;
    }
};
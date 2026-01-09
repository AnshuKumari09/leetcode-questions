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
   
    int findHeight(TreeNode* root,int h){
        if(root==NULL){
            return 0;
        }
      int leftH=findHeight(root->left,h+1);
       int rightH=findHeight(root->right,h+1);
          return 1+max(leftH,rightH);
    }

    TreeNode* solve(TreeNode* root){
        if(root==NULL){
            return NULL;
        }
        int lh=findHeight(root->left,0);
        int rh=findHeight(root->right,0);
        if(lh==rh){
            return root;
        }
        else if(lh>rh){
            return solve(root->left);
        }
         return solve(root->right);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
       return solve(root);
    }
};
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
// class Solution {
// public:
// int maxDiff=INT_MIN;
//      void checkMaxDiff(TreeNode* root,int rootVal){
//         if(root==NULL){
//             return;
//         }
//         int currDiff=abs(rootVal-root->val);
//         maxDiff=max(maxDiff,currDiff);
//        checkMaxDiff(root->left,rootVal);
//        checkMaxDiff(root->right,rootVal); 
//      }
//     void traverse(TreeNode* root){
//         if(root==NULL){
//             return;
//         }
//         checkMaxDiff(root,root->val);
//         traverse(root->left);
//         traverse(root->right);
//     }
//     int maxAncestorDiff(TreeNode* root) {
//        traverse(root);
//         return maxDiff;
//     }
// };

class Solution {
public:
     int maxDiff=0;
     void traverse(TreeNode* root,pair<int,int>p){
        if(root==NULL){
            return;
        }
        if(root->val<p.first){
            p.first=root->val;
        }

        if(root->val>p.second){
            p.second=root->val;
        }
        if(!root->left && !root->right){ // agr node leaf hai toh
           int diff=p.second-p.first;
           maxDiff=max(maxDiff,diff);

        }

        traverse(root->left,p);
        traverse(root->right,p);
     }
    int maxAncestorDiff(TreeNode* root) {
        pair<int,int>p={root->val,root->val};
        // min, max
       traverse(root,p);
        return maxDiff;
    }
};
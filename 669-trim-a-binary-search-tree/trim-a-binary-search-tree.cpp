// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:

//     TreeNode* dfs(TreeNode* root, int low, int high){
//         if(root==NULL){
//             return NULL;
//         }
//         if(!root->right && !root->left){
//             if(root->val>high || root->val<low){
//                if(root->left){
//                 return root->left;

//                }
//                else if(root->right){
//                 return root->right;
//                }
//             }
  
//         }
//     TreeNode* leftNode=dfs(root->left,low,high);
//      TreeNode* rightNode=dfs(root->right,low,high);
//     }
//     TreeNode* trimBST(TreeNode* root, int low, int high) {
//         return dfs(root,low,high);
//     }
// };


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

    TreeNode* dfs(TreeNode* root, int low, int high) {

        if(root == NULL) {
            return NULL;
        }

        root->left = dfs(root->left, low, high);
        root->right = dfs(root->right, low, high);

        if(root->val > high) {
            return root->left;
        }

        if(root->val < low) {
            return root->right;
        }

        return root;
    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return dfs(root, low, high);
    }
};

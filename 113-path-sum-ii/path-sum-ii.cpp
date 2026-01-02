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
    vector<vector<int>>result;
   void checkTheSum(TreeNode* root,int targetSum,int currSum,vector<int>vec){
        if(root==NULL){
            return;
        }
        
        currSum+=root->val;
         vec.push_back(root->val);
         if(currSum==targetSum && !root->left && !root->right){
            result.push_back(vec);
         }
         checkTheSum(root->left,targetSum,currSum,vec);
         checkTheSum(root->right,targetSum,currSum,vec);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>vec;
        checkTheSum(root,targetSum,0,vec);
        return result;
    }
};
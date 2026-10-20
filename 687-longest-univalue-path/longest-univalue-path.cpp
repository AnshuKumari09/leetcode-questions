class Solution {
public:
    int longestPath;

    pair<int,int> solve(TreeNode* root) {
        if (root == NULL) {
            return {0, 0};
        }

        pair<int,int> l = solve(root->left);
        pair<int,int> r = solve(root->right);

        int leftFreq = 0;
        int rightFreq = 0;

        if (root->left != NULL && root->left->val == root->val) {
            leftFreq = l.second + 1;
        }

        if (root->right != NULL && root->right->val == root->val) {
            rightFreq = r.second + 1;
        }

        longestPath = max(longestPath, leftFreq + rightFreq);

        return {root->val, max(leftFreq, rightFreq)};
    }

    int longestUnivaluePath(TreeNode* root) {
        longestPath = 0;
        solve(root);
        return longestPath;
    }
};

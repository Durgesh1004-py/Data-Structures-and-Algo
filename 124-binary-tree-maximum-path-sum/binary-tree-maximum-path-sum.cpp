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
    int maxisumpath(TreeNode* root, int &maxsum)
    {
        if(root==NULL) return 0;

        int lh = maxisumpath(root->left, maxsum);
        int rh = maxisumpath(root->right, maxsum);

        maxsum = max(maxsum, root->val + max(0, lh) + max(0, rh));

        return root->val + max(0, max(lh, rh));
    }
    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        maxisumpath(root, maxsum);
        return maxsum;
        
    }
};
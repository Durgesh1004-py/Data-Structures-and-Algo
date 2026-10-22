class Solution {
public:

    void solve(TreeNode* root, long long& small, long long& ans){
        if(root == nullptr){
            return;
        }

        // Found a new smallest value
        if(root->val < small){
            ans = small;
            small = root->val;
        }

        // Found a possible second smallest distinct value
        else if(root->val > small && root->val < ans){
            ans = root->val;
        }

        solve(root->left, small, ans);
        solve(root->right, small, ans);
    }

    int findSecondMinimumValue(TreeNode* root) {
        long long small = LLONG_MAX;
        long long ans = LLONG_MAX;

        solve(root, small, ans);

        return ans == LLONG_MAX ? -1 : ans;
    }
};
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
    void helper(TreeNode* root, int cnt, bool left, bool right, int &ans)
    {
        if(root==NULL) return;

        ans = max(ans, cnt);
        
        if(root->left!=NULL)
        {
            if(left)
            {
                helper(root->left,cnt+1, false, true, ans);
            }
            else
            {
                helper(root->left, 1 ,false, true, ans);
            }
            
        }
        if(root->right!=NULL)
        {
            if(right==true)
            {
                helper(root->right, cnt+1, true, false, ans);
            }
            else
            {
                helper(root->right, 1, true, false, ans);
            }
        }

    }
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        helper(root, 0,true, false, ans);
        return ans;
        
    }
};
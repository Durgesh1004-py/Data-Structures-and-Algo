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
    void storeValues(TreeNode* root,vector<int> &store)
    {
        if(root==NULL)
        {
            return ;
        }

        storeValues(root->left,store);
        store.push_back(root->val);
        storeValues(root->right,store);

    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> store;
        storeValues(root,store);

        return store[k-1];

        
    }
};
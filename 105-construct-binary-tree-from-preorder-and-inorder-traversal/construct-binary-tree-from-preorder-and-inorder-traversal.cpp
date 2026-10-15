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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mpp;
        for(int i=0; i<inorder.size(); i++)
        {
            mpp[inorder[i]] = i;
        }

        TreeNode* node = buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mpp);

        return node;
        
    }

    TreeNode* buildTree(vector<int>& preorder, int prestart, int preend, vector<int>& inorder, int instart, int inend, map<int,int> &mpp)
    {
        if(prestart>preend || instart>inend) return NULL;

        TreeNode* node = new TreeNode(preorder[prestart]);

        int inRoot = mpp[node->val];
        int numsleft = inRoot - instart;

        node->left = buildTree(preorder, prestart+1, prestart+numsleft, inorder, instart, inRoot-1, mpp);

        node->right = buildTree(preorder, prestart+numsleft+1, preend, inorder, inRoot+1, inend, mpp);

        return node;
    }
};
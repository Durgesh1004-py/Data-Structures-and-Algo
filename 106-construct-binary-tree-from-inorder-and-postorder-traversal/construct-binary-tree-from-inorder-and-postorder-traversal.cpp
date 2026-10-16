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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mpp;
        for(int i=0; i<inorder.size(); i++)
        {
            mpp[inorder[i]] = i;
        }

        return building(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, mpp);
    }

    TreeNode* building(vector<int>& inorder,int is, int ie, vector<int>& postorder, int ps, int pe, map<int,int> &mpp)
    {
        if(ps>pe || is>ie) return NULL;

        TreeNode* root = new TreeNode(postorder[pe]);

        int inroot = mpp[postorder[pe]];
        int numleft = inroot - is;

        root->left = building(inorder, is, inroot-1, postorder, ps, ps+numleft-1, mpp);
        root->right = building(inorder, inroot+1, ie, postorder, ps+numleft,pe-1, mpp);

        return root;
    }
};
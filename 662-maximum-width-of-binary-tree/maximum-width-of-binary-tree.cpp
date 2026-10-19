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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        
        long long maxlen = 1;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});

        while(!q.empty())
        {
            int level_size = q.size();
            long long st = q.front().second;
            long long end = q.back().second;
            maxlen = max(maxlen, end-st+1);

            for(int i=0; i<level_size; i++)
            {
                auto node_pair = q.front();
                TreeNode* node = node_pair.first;
                long long node_index = node_pair.second - st;
                q.pop();

                if(node->left!=nullptr)
                {
                    q.push({node->left, 2LL * node_index+1});
                }
                if(node->right!=nullptr)
                {
                    q.push({node->right, 2LL * node_index+2});
                }
            }

        }
        return maxlen;
    }
};
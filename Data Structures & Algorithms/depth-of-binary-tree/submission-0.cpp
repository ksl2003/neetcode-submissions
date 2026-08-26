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
private:
    int maxH(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int leftMaxH = maxH(root->left);
        int rightMaxH = maxH(root->right);

        return 1 + max(leftMaxH, rightMaxH);
    }

public:
    int maxDepth(TreeNode* root) {
        int ans = maxH(root);

        return ans;
    }
};

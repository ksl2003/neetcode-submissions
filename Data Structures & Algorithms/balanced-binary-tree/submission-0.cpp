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
    int maxH(TreeNode* root, bool &ans){
        if(root==NULL){
            return 0;
        }

        int leftMaxH = maxH(root->left, ans);
        int rightMaxH = maxH(root->right, ans);

        if(abs(leftMaxH-rightMaxH)>1){
            ans = false;
        }

        return 1 + max(leftMaxH, rightMaxH);
    }

public:
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        int maxHeight = maxH(root, ans);
        return ans;
    }
};

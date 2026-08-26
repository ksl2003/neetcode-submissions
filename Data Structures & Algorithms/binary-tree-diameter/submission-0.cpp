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
    int maxD(TreeNode* root, int &ans){
        if(root==NULL){
            return 0;
        }

        int leftMaxD = maxD(root->left, ans);
        int rightMaxD = maxD(root->right, ans);

        ans = max(ans, leftMaxD+rightMaxD+1);

        return 1 + max(leftMaxD, rightMaxD);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        int maxHeight = maxD(root, ans);
        return ans-1;
    }
};

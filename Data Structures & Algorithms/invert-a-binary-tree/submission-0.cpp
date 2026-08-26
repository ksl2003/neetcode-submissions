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
    TreeNode* reversedRoot(TreeNode* root){
        if(root==NULL){
            return root;
        }
        reversedRoot(root->left);
        reversedRoot(root->right);
        TreeNode* leftNode = NULL;
        TreeNode* rightNode = NULL;
        if(root->left!=NULL){
            leftNode = root->left;
        }
        if(root->right!=NULL){
            rightNode = root->right;
        }

        root->left = rightNode;
        root->right = leftNode;

        return root;
    }

public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* finalRoot = reversedRoot(root);
        return finalRoot;
    }
};

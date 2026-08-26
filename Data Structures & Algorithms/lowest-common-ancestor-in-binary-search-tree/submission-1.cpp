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
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &ans){
        if(root==NULL){
            return NULL;
        }


        TreeNode* leftNode = solve(root->left, p, q, ans);
        TreeNode* rightNode = solve(root->right, p, q, ans);

        if((leftNode==p && rightNode==q) || (leftNode==q && rightNode==p)){
            ans = root;
            return root;
        }
        if(((leftNode==p || rightNode==p) && root==q ) || ((leftNode==q || rightNode==q) && root==p)){
            ans = root;
            return root;
        }

        if(root==p || root==q){
            return root;
        }
        if(leftNode){
            return leftNode;
        }
        if(rightNode){
            return rightNode;
        }
        return NULL;
    }


public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        TreeNode* temp = solve(root, p, q, ans);
        return ans;
    }
};

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
void solve(TreeNode* root, int &goodNodes, int presMax){
    if(root==NULL){
        return;
    }

    if(root->val>=presMax){
        goodNodes++;
    }
    int finalMax = max(presMax, root->val);
    
    solve(root->left, goodNodes, finalMax);
    solve(root->right, goodNodes, finalMax);
}

public:
    int goodNodes(TreeNode* root) {
        int goodNodes = 0;
        if(root==NULL){
            return 0;
        }
        int presMax = root->val;
        solve(root, goodNodes, presMax);
        return goodNodes;
    }
};

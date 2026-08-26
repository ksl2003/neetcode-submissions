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
// #typedef long long int ll;

class Solution {
private:
    bool solve(TreeNode* root, int low, int high){
        if(root==NULL){
            return true;
        }

        bool leftAns = solve(root->left, low, root->val);
        bool rightAns = solve(root->right, root->val, high);


        if(!(root->val>low && root->val<high)){
            return false;
        }

        return leftAns && rightAns;
    }

public:
    bool isValidBST(TreeNode* root) {
        bool ans = solve(root, INT_MIN, INT_MAX);
        return ans;
    }
};

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
    bool solve(TreeNode* root, TreeNode* subRoot){
        if(root==NULL && subRoot==NULL){
            return true;
        }
        if(root==NULL || subRoot==NULL){
            return false;
        }

        bool leftAns = solve(root->left, subRoot->left);
        bool rightAns = solve(root->right, subRoot->right);

        bool presAns = false;
        if(root->val==subRoot->val){
            presAns = true;
        }

        return (presAns && leftAns && rightAns);

    }

    bool findRoot(TreeNode* root, TreeNode* subRoot){
        if(root == NULL)
            return false;

        if(root->val == subRoot->val){
            if(solve(root, subRoot))
                return true;
        }

        return findRoot(root->left, subRoot) || findRoot(root->right, subRoot);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // TreeNode* presRoot = findRoot(root, subRoot);
        bool ans = findRoot(root, subRoot);
        return ans;
    }
};

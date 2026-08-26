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
    bool solve(TreeNode* p, TreeNode* q){
        if(p==NULL && q==NULL){
            return true;
        }
        if(p==NULL || q==NULL){
            return false;
        }

        bool leftAns = solve(p->left, q->left);
        bool rightAns = solve(p->right, q->right);

        bool presAns = true;
        if(p->val!=q->val){
            presAns = false;
        }

        return (presAns && leftAns && rightAns);
    }

public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans = solve(p, q);
        return ans;
    }
};

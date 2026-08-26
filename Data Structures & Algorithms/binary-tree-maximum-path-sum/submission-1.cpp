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
    int solve(TreeNode* root, int& maxSum) {
        if (root == NULL) {
            return INT_MIN;
        }

        int leftMaxSum = max(0, solve(root->left, maxSum));
        int rightMaxSum = max(0, solve(root->right, maxSum));

        int twoSidesSum = leftMaxSum + rightMaxSum + root->val;

        maxSum = max(maxSum, twoSidesSum);

        return root->val + max(leftMaxSum, rightMaxSum);
    }

   public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int temp = solve(root, maxSum);
        return maxSum;
    }
};

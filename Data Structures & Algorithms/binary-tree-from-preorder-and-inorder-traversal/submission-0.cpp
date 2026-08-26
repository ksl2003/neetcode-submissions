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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& preOrderIdx, int low, int high) {
        if (low > high) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preOrderIdx]);
        int presVal = preorder[preOrderIdx];

        int preOrdValI = -1;

        for (int i = low; i <= high; i++) {
            if (inorder[i] == presVal) {
                preOrdValI = i;
                break;
            }
        }

        preOrderIdx++;
        root->left = solve(preorder, inorder, preOrderIdx, low, preOrdValI - 1);
        root->right = solve(preorder, inorder, preOrderIdx, preOrdValI + 1, high);

        return root;
    }

   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int low = 0, high = n - 1;
        int preOrderIdx = 0;
        TreeNode* root = solve(preorder, inorder, preOrderIdx, low, high);
        return root;
    }
};

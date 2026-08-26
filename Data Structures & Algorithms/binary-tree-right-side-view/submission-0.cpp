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
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        while(!q.empty()){
            vector<TreeNode*> nxtLvlNodes;
            vector<int> presLvl;
            while(!q.empty()){
                auto presNode = q.front();
                q.pop();
                presLvl.push_back(presNode->val);

                if(presNode->left){
                    nxtLvlNodes.push_back(presNode->left);
                }
                if(presNode->right){
                    nxtLvlNodes.push_back(presNode->right);
                }
            }
            ans.push_back(presLvl);
            for(auto a: nxtLvlNodes){
                q.push(a);
            }
        }
        vector<int> presAns;
        for(auto a: ans){
            presAns.push_back(a.back());
        }
        return presAns;
    }
};

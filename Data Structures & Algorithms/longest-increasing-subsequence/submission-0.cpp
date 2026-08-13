class Solution {
private:
    int dp(vector<int> &nums, int pres, int prev, vector<vector<int>> &dpMat){
        if(pres>=nums.size()){
            return 0;
        }
        
        if(dpMat[pres][prev+1]!=-1){
            return dpMat[pres][prev+1];
        }
        int exclude = dp(nums, pres+1, prev, dpMat);
        int include = 0;
        if(prev==-1 || nums[pres]>nums[prev]){
            include = 1 + dp(nums, pres+1, pres, dpMat);
        }

        return dpMat[pres][prev+1] = max(exclude, include);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dpMat(n+1, vector<int> (n+2, -1));
        int ans = dp(nums, 0, -1, dpMat);
        return ans;
    }
};

class Solution {
private:
    int dp(vector<int> &nums, int n, vector<int> &dpMat){
        if(n>=nums.size()){
            return 0;
        }
        if(dpMat[n]!=-1){
            return dpMat[n];
        }

        int ans = max(dp(nums, n+1, dpMat), (nums[n]+dp(nums, n+2, dpMat)));
        return dpMat[n] = ans;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dpMat(n+1, -1);
        int ans = dp(nums, 0, dpMat);
        return ans;
    }
};

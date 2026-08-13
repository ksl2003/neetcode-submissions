class Solution {
private:
    int dp(vector<int> &nums, int i, vector<int> &dpMat){
        if(i>=nums.size()){
            return 0;
        }
        if(dpMat[i]!=-1){
            return dpMat[i];
        }

        int ans = max(dp(nums, i+1, dpMat), (nums[i]+dp(nums, i+2, dpMat)));
        return dpMat[i] = ans;
    }

public:
    int rob(vector<int>& nums) {
        vector<int> nums1; 
        vector<int> nums2;
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        for(int i=0; i<n-1; i++){
            nums1.push_back(nums[i]);
        }
        for(int i=1; i<n; i++){
            nums2.push_back(nums[i]);
        }
        vector<int> dpMat1(n, -1), dpMat2(n, -1);
        int ans = dp(nums1, 0, dpMat1);
        ans = max(ans, dp(nums2, 0, dpMat2));
        return ans;
    }
};

class Solution {
private:
    bool dp(vector<int> &nums,int i, int target, vector<vector<int>> &dpMat){
        if(target==0){
            return true;
        }
        if(i>=nums.size() || target<0){
            return false;
        }
        if(dpMat[i][target]!=-1){
            return dpMat[i][target];
        }

        bool notTake = dp(nums, i+1, target, dpMat);
        bool take = dp(nums, i+1, target-nums[i], dpMat);

        return dpMat[i][target] = (take||notTake);

    }

public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto a: nums){
            sum+= a;
        }
        if(sum%2){
            return false;
        }
        int n = nums.size();
        vector<vector<int>> dpMat(n+1, vector<int>((sum/2) + 1, -1));
        bool ans = dp(nums, 0, sum/2, dpMat);
        return ans;
    }
};

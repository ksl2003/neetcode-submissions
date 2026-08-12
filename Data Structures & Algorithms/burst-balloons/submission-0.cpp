class Solution {
private:
    int dp(vector<int> &nums, int l, int r, vector<vector<int>> &dpMat) {
        if(l > r)
            return 0;

        if(dpMat[l][r] != -1)
            return dpMat[l][r];

        int ans = 0;

        for(int i = l; i <= r; i++) {
            ans = max(ans,
                dp(nums, l, i - 1, dpMat) +
                nums[l - 1] * nums[i] * nums[r + 1] +
                dp(nums, i + 1, r, dpMat)
            );
        }

        return dpMat[l][r] = ans;
    }

public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dpMat(n + 2, vector<int>(n + 2, -1));

        return dp(nums, 1, n, dpMat);
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int, int> mp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int diff = target - nums[i];
            if(mp.count(diff)){
                ans.push_back(mp[diff]);
                ans.push_back(i);
                return ans;
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixMul(n), suffixMul(n);
        int presMul = 1;
        for(int i=0; i<n; i++){
            prefixMul[i] = presMul;
            presMul = presMul*nums[i];
        }
        presMul = 1;
        for(int i=n-1; i>=0; i--){
            suffixMul[i] = presMul;
            presMul = presMul*nums[i];
        }
        vector<int> ans;

        for(int i=0; i<n; i++){
            int prefSum = prefixMul[i];
            int suffSum = suffixMul[i];
            ans.push_back(prefSum*suffSum);
        }
        return ans;
    }
};

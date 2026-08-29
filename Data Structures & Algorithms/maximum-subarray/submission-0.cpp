class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ansSum = INT_MIN;
        int n = nums.size();
        int presSum = 0;
        for(auto a: nums){
            presSum+=a;
            ansSum = max(ansSum, presSum);
            if(presSum<0){
                presSum = 0;
            }
        }
        return ansSum;
    }
};

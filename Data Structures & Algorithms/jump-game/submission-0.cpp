class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int presGoal = n-1;
        for(int i=n-2; i>=0; i--){
            int presDiff = presGoal - i;
            int presJump = nums[i];
            if(presDiff<=presJump){
                presGoal = i;
            }
        }
        if(presGoal == 0){
            return true;
        }
        return false;
    }
};

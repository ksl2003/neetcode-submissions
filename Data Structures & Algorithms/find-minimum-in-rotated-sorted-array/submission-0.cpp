class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        bool isRev = false;
        if(nums[0]>nums[n-1]){
            isRev=true;
        }
        if(!isRev){
            return nums[0];
        }

        while(low<=high){
            int mid = (low + high)/2;

            if(nums[mid]>=nums[0]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return nums[low];
    }
};

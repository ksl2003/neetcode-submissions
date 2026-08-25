class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==1){
            if(nums[0]==target){
                return 0;
            }
            return -1;
        }
        int low = 0, high = n-1;
        bool isRev = false;

        if(nums[0]>nums[n-1]){
            isRev=true;
        }
        int minNumIdx = -1;
        if(!isRev){
            minNumIdx = 0;
        }

        while(low<=high && isRev){
            int mid = (low + high)/2;

            if(nums[mid]>=nums[0]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        if(isRev)
        minNumIdx = low;

        if(target>=nums[minNumIdx] && target<=nums[n-1]){
            low = minNumIdx;
            high = n-1;
        }
        else{
            low = 0;
            high = minNumIdx-1;
        }

        while(low<=high){
            int mid = (low+high)/2;

            if(nums[mid]<=target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        if(high>=0 && nums[high] != target){
            return -1;
        }
        return high;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> maxHeap;
        int start = 0, end = k-1;
        int n = nums.size();
        for(int i=start; i<=end; i++){
            maxHeap.push({nums[i], i});
        }
        vector<int> ans;
        ans.push_back(maxHeap.top().first);
        start++;
        end++;
        while(end<n){
            maxHeap.push({nums[end], end});
            while(maxHeap.top().second<start){
                maxHeap.pop();
            }
            ans.push_back(maxHeap.top().first);
            start++;
            end++;
        }
        return ans;
    }
};

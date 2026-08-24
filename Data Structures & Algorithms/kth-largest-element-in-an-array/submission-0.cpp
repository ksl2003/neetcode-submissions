class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(auto a: nums){
            if(minHeap.size()<k){
                minHeap.push(a);
            }
            else{
                if(minHeap.top()<a){
                    minHeap.pop();
                    minHeap.push(a);
                }
            }
        }
        return minHeap.top();
    }
};

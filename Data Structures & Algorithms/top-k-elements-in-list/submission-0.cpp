class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freqNums;
        for(auto a: nums){
            freqNums[a]++;
        }

        priority_queue<pair<int, int>> maxHeap;
        for(auto [key, val]: freqNums){
            maxHeap.push({val, key});
        }
        vector<int> ans;
        while(k--){
            auto presEle = maxHeap.top();
            maxHeap.pop();
            ans.push_back(presEle.second);
        }
        return ans;
    }
};

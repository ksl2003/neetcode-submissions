class Solution {

public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(auto a: stones){
            maxHeap.push(a);
        }

        while(maxHeap.size()>1){
            int x = maxHeap.top();
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();

            int diff = abs(y-x);
            if(diff!=0){
                maxHeap.push(diff);
            }
        }
        if(maxHeap.size()!=0){
            return maxHeap.top();
        }
        return 0;
    }
};

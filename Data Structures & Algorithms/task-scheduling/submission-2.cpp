class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int gap = n+1;
        int taskSize = tasks.size();

        vector<int> freqCnt(26, 0);
        for(int i=0; i<taskSize; i++){
            int idx = (int)(tasks[i]-'A');
            freqCnt[idx]++;
        }

        priority_queue<int> maxHeap;
        for(int i=0; i<26; i++){
            if(freqCnt[i])
            maxHeap.push(freqCnt[i]);
        }

        int ans =  0;
        while(!maxHeap.empty()){
            int presCycles = 0;
            vector<int> freqTemp;
            while(!maxHeap.empty() && presCycles < gap){
                int presFreq = maxHeap.top();
                maxHeap.pop();

                presCycles++;
                presFreq--;
                if(presFreq){
                    freqTemp.push_back(presFreq);
                }
            }
            int ansTemp = presCycles;
            if(!freqTemp.empty())
                ansTemp += gap - presCycles;
            ans += ansTemp;
            for(auto a: freqTemp){
                maxHeap.push(a);
            }
        }
        return ans;
    }
};

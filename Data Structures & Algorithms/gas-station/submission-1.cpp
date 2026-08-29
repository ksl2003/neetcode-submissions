class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> diff(n, 0);
        for(int i=0; i<n; i++){
            int presDiff = gas[i]-cost[i];
            diff[i] = presDiff;
        }

        int presIdx = 0;
        int totalSum = 0;
        int totalDiff = 0;
        for(int i=0; i<n; i++){
            totalSum += diff[i];
            totalDiff += diff[i];
            if(totalSum<0){
                totalSum = 0;
                presIdx = i+1;
            }
        }
        if(totalDiff<0){
            return -1;
        }
        return presIdx;
    }
};

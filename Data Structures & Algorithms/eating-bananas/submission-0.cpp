class Solution {
private:
    bool isPossible(vector<int> &piles, int h, int presK){
        int ansH = 0;
        for(auto a: piles){
            int presBananas = a;
            double presk = presK*1.0;
            ansH += ceil(presBananas/presk);
        }
        if(ansH<=h){
            return true;
        }
        return false;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = piles[0];
        for(auto a: piles){
            high = max(high, a);
        }

        while(low<=high){
            int mid = (low+high)/2;

            if(isPossible(piles, h, mid)){
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};

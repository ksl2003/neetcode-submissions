class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0;
        int j = n-1;
        while(i<j){
            int presSum = numbers[i] + numbers[j];
            if(presSum==target){
                return {i+1, j+1};
            }
            else if(presSum<target){
                i++;
            }
            else{
                j--;
            }
        }
        return {};
    }
};

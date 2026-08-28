class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0;
        int j = n-1;
        int presAns = 0;

        while(i<j){
            int presWidth = (j-i);
            int presHeight = min(heights[i], heights[j]);
            int tempAns = presWidth*presHeight;
            presAns = max(presAns, tempAns);

            if(heights[i]<heights[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return presAns;
    }
};

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<vector<int>> filterTriplets;
        int tar_u = target[0];
        int tar_v = target[1];
        int tar_w = target[2];

        int max_u = -1;
        int max_v = -1;
        int max_w = -1;

        for(auto a: triplets){
            int u = a[0];
            int v = a[1];
            int w = a[2];

            if(!(u>tar_u || v>tar_v || w>tar_w)){
                filterTriplets.push_back(a);
                max_u = max(max_u, u);
                max_v = max(max_v, v);
                max_w = max(max_w, w);
            }
        }
        if(max_u==tar_u && max_v==tar_v && max_w==tar_w){
            return true;
        }
        return false;

    }
};

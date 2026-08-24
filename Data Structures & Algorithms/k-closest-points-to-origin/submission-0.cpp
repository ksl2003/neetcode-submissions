class Solution {
private:
    int findDistt(int x, int y){
        return ((x*x) + (y*y));
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        int n = points.size();
        for(int i=0; i<n; i++){
            vector<int> a = points[i];
            int u = a[0];
            int v = a[1];
            int getDist = findDistt(u, v);
            minHeap.push({getDist, i});
        }
        vector<vector<int>> ans;
        while(ans.size()<k){
            auto ele = minHeap.top();
            minHeap.pop();

            int idx = ele.second;
            ans.push_back(points[idx]);
        }
        return ans;
    }
};

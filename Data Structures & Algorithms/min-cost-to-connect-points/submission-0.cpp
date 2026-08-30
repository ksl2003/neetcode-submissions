class Solution {
private:
    void fillAdjList(vector<vector<int>> &points, vector<vector<pair<int,int>>> &adjList){

        int n = points.size();
        for(int i=0; i<n; i++){
            for(int j = i+1; j<n; j++){
                auto firstPt = points[i];
                auto secondPt = points[j];

                int len = abs(firstPt[0]-secondPt[0]) + abs(firstPt[1]-secondPt[1]);
                adjList[i].push_back({j, len});
                adjList[j].push_back({i, len});
            }
        }
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adjList(n);
        fillAdjList(points, adjList);


        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > minHeap;
        vector<bool> visited(n, false);

        int minSum = 0;
        int cnt = 0;
        minHeap.push({0, 0});
        while(!minHeap.empty()){
            auto ele = minHeap.top();
            minHeap.pop();
            int presDis = ele.first;
            int presEle = ele.second;

            if(visited[presEle]==true){
                continue;
            }

            visited[presEle]=true;
            minSum += presDis;
            cnt++;
            for(auto a: adjList[presEle]){
                if(!visited[a.first]){
                    minHeap.push({a.second, a.first});
                }
            }
        }
        if(cnt!=n){
            return -1;
        }
        else{
            return minSum;
        }
    }
};

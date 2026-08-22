class Solution {
   private:
    int dp(vector<vector<pair<int, int>>>& adj, int node, int dst, int stops, vector<vector<int>>& memo) {
        if (node == dst){
            return 0;
        } 
        if (stops == 0){
            return 1e9;
        } 

        if (memo[node][stops] != -1) return memo[node][stops];
        int ans = 1e9;
        for (auto [next, wt] : adj[node]) {
            int cost = dp(adj, next, dst, stops - 1, memo);

            if (cost != 1e9) ans = min(ans, wt + cost);
        }
        return memo[node][stops] = ans;
    }

   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& f : flights){
            adj[f[0]].push_back({f[1], f[2]});
        } 
        vector<vector<int>> memo(n, vector<int>(k+2, -1));
        int ans = dp(adj, src, dst, k+1, memo);
        return ans == 1e9 ? -1 : ans;
    }
};
class Solution {
private:
    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j, int rows, int cols, int &ans){
        if(i>=rows || j>=cols || i<0 || j<0 || visited[i][j] || grid[i][j]==0){
            return;
        }
        visited[i][j] = true;
        ans++;

        dfs(grid, visited, i+1, j, rows, cols, ans);
        dfs(grid, visited, i-1, j, rows, cols, ans);
        dfs(grid, visited, i, j+1, rows, cols, ans);
        dfs(grid, visited, i, j-1, rows, cols, ans);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int finalAns = 0;
        vector<vector<bool>> visited(rows+1, vector<bool> (cols+1, false));
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(!visited[i][j] && grid[i][j]==1){
                    int ans = 0;
                    dfs(grid, visited, i, j, rows, cols, ans);
                    finalAns = max(finalAns, ans);
                }
            }
        }
        return finalAns;
    }
};

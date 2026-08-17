class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int INF = INT_MAX;
        vector<vector<int>> shortDis(rows, vector<int> (cols, INF));

        queue<pair<int, int>> q;
        
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]==0){
                    q.push({i, j});
                    shortDis[i][j] = 0;
                }
                if(grid[i][j]==-1){
                    shortDis[i][j]=-1;
                }
            }
        }

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int presDis = shortDis[r][c];
            if(r<rows-1 && grid[r+1][c]==INF && shortDis[r+1][c]==INF){
                shortDis[r+1][c] = presDis+1;
                q.push({r+1, c});
            }
            if(c<cols-1 && grid[r][c+1]==INF && shortDis[r][c+1]==INF){
                shortDis[r][c+1] = presDis+1;
                q.push({r, c+1});
            }
            if(r>0 && grid[r-1][c]==INF && shortDis[r-1][c]==INF){
                shortDis[r-1][c] = presDis+1;
                q.push({r-1, c});
            }
            if(c>0 && grid[r][c-1]==INF && shortDis[r][c-1]==INF){
                shortDis[r][c-1] = presDis+1;
                q.push({r, c-1});
            }
        }
        
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                grid[i][j] = shortDis[i][j];
            }
        }
    }
};

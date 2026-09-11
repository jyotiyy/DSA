iterating over the boundary and traversing where the cell value is 1
and then checking over the complete grid 
now whichever indexes are visited cannot be counted



class Solution {
public:
    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,1,-1};
    void dfs(int i,int j,vector<vector<int>> &grid,vector<vector<bool>> &used){
        int r = grid.size();
        int c = grid[0].size();
        used[i][j] = true;
        for(int k = 0; k < 4; k++){
            int nr = i+dr[k];
            int nc = j+dc[k];
            if(nr >= 0 && nc >= 0 && nr < r && nc < c
            && !used[nr][nc] && grid[nr][nc] == 1){
                dfs(nr,nc,grid,used);
            }
        }


    }
    int numEnclaves(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<bool>> vis(r,vector<bool>(c,false));

        //traverse over the boundary
        for(int i = 0; i < c; i++){
            if(!vis[0][i] && grid[0][i] == 1){
                dfs(0,i,grid,vis);
            }
            if(!vis[r-1][i] && grid[r-1][i] == 1){
                dfs(r-1,i,grid,vis);
            }
        }
        for(int i = 0; i < r; i++){
            if(!vis[i][0] && grid[i][0] == 1){
                dfs(i,0,grid,vis);
            }
            if(!vis[i][c-1] && grid[i][c-1] == 1){
                dfs(i,c-1,grid,vis);
            }
        }
        int cnt = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
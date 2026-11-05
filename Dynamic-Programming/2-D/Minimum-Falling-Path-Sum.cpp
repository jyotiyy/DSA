class Solution {
public:
    int dx[3] = {1,1,1};
    int dy[3] = {-1,0,1};
    int dp[101][101];
    bool vis[101][101];
    int n;
    int dfs(vector<vector<int>> &mat,int r,int c){
        
        if (r < 0 || c < 0 || r >= n || c >= n)
            return 1e9;
        
        if(r == n-1)return mat[r][c];
        if(vis[r][c])return dp[r][c];
        int ans = 1e9;;
vis[r][c] = true;
        for(int i = 0; i< 3; i++){
            int ndx = dx[i]+r;
            int ndy = dy[i]+c;
            ans = min(dfs(mat,ndx,ndy),ans);

        }
        return dp[r][c] = mat[r][c]+ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        int res = INT_MAX;
    
        memset(vis,false,sizeof(vis));
        for(int i = 0; i < n; i++){
            res = min(dfs(matrix,0,i),res);
        }
        return res;

    }
};
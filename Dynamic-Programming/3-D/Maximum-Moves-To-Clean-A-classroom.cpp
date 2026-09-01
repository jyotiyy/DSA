class Solution {
public:
    static constexpr int dx[4] = {0,1,-1,0};
    static constexpr int dy[4] = {1,0,0,-1};
    /*The idea is to keep note of dp[x][y][mask] , that is the maximum energy possible at a position x,y . Also a predefined mask is stored so that we have a hold over the liters cleaned till now */
    int minMoves(vector<string>& classroom, int energy) {

        int n = classroom.size();
        int m = classroom[0].size();
        vector<vector<int>> id(n,vector<int>(m,0));
        int sx,sy,cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(classroom[i][j] == 'S'){
                    sx = i;
                    sy = j;
                }else if(classroom[i][j] == 'L'){
                    id[i][j] = (1<<cnt++);
                }
            }
        }

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(
                m,
                vector<int>(1<<cnt,-1);
            )
        )

        struct info{
            int x,y,m,e,s;
        }
        queue<info> q;
        q.push({sx,sy,0,energy,0});
        while(!q.empty()){
            info t = q.front();
            q.pop();
            if(t.m == (1<<cnt)-1) return t.s;
            if(t.e == 0) continue;
            for(int i = 0; i < 4; i++){
                int nx = t.x + dx[i];
                int ny = t.y + dy[i];
                if(nx <0 || ny < 0 || nx >= n || ny >= m || classroom[nx][ny] == 'X') continue;

                int ne = (classroom[nx][ny] == 'R')? energy: t.e-1;
                int nmask = t.m | id[nx][ny];
                if(ne > dp[nx][ny][nmask]){
                    dp[nx][ny][nmask] = ne;
                    q.push({nx,ny,nmask,ne,t.s+1});
                }

            }
        }
        return -1;
        

        
    }
};
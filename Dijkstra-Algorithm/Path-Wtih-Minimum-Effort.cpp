// we binary search the k value for which we check with the whole matrix from top left to bottom right
// We are treating each cell as a node in graph . Moving between 2 cells has an effort of abosulte difference between their heights. For a path the total effort is the maximum effort of any single move on the path
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        dist[0][0] = 0;
        pq.push({0,0,0});
        while(!pq.empty()){
            auto [eff,r,c] = pq.top();
            pq.pop();
            if(r == m-1 && c == n-1) return eff;
            for(auto d:dir){
                int nr = d[0]+r;
                int nc = d[1]+c;
                if(nr >=0 && nr < m && nc >= 0 && nc < n){
                    int neweff = max(eff,abs(heights[r][c]-heights[nr][nc]));
                    if(neweff < dist[nr][nc]){
                        dist[nr][nc] = neweff;
                        pq.push({neweff,nr,nc});
                    }
                }
            }
        }
        return 0;
    }
};
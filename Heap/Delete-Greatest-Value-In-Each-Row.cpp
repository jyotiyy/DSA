class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int r = grid.size();
        vector<priority_queue<int>> vp(r);
        int i = 0;
        for(vector<int> &row: grid){
            priority_queue<int> cur;
            for(int x: row) cur.push(x);
            vp[i++] = cur;
        }
        int res = 0;
        int c = grid[0].size();
        for(int i = 0; i < c; i++){
            int mx = -1;
            for(priority_queue<int>&p: vp){
                mx = max(mx,p.top());
                p.pop();
            }
            res+=mx;
        }
        return res;

    }
};
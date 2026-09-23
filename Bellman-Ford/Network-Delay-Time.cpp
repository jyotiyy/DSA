repear v-1 times 
   for every edge relax it 
   
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> res(n+1,INT_MAX);
        res[k] = 0;
        for(int i = 0; i < n-1; i++){
            for(auto &edge: times){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                if(res[u] != INT_MAX){
                    res[v] = min(res[v],res[u]+w);
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            int x = res[i];
            if(x == INT_MAX) return -1;
            ans = max(ans,x);
        }
        return ans;
    }
};
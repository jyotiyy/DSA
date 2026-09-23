The idea is to have a min heap to store the paired destination with least distance till now , and explore it further . Also pruning unessary nodes

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> res(n+1,INT_MAX);
        int ans = -1;
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &x: times){
            int u = x[0];
            int v = x[1];
            int w = x[2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        res[k] = 0;
        pq.push({0,k});
        while(!pq.empty()){
            auto temp = pq.top();
            int dist = temp.first;
            int node = temp.second;
            pq.pop();
            if(dist > res[node]) continue;
            for(auto &x: adj[node]){
                int v = x.first;
                int wt= x.second;
                if(wt+dist < res[v]){
                    res[v] = wt+dist;
                    pq.push({wt+dist,v});
                }
            }
        }
        for(int i = 1; i <= n; i++){
            if(res[i] == INT_MAX){
                return -1;
            }
            ans = max(ans,res[i]);
        }
        return ans;
    }
};
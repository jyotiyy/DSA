class Solution {
public:
    bool check(vector<vector<int>> &adj,int n,int d,vector<bool> &vis){
        if(n == d) return true;
        vis[n] = true;
        for(int ngh: adj[n]){
            if(!vis[ngh]){
                if(check(adj,ngh,d,vis)) return true;
            }
        }
        return false;
        
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n+1);
        for(vector<int> &edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n,false);
        return check(adj,source,destination,vis);
    }
};
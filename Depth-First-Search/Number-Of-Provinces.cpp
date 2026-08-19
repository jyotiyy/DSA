link: https://leetcode.com/problems/number-of-provinces/
Basically finding the individual connected components ;)

class Solution {
public:
    void dfs(vector<bool> &visit,int node,vector<vector<int>>& isConnected){
        visit[node] = true;
        for(int i = 0; i < isConnected.size(); i++){
            if(isConnected[node][i] == 1 && !visit[i]){
                dfs(visit,i,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int p = 0;
        int n = isConnected.size();
        vector<bool> visit(n);
        for(int i = 0; i < n; i++){
            if(!visit[i]){
                p++;
                dfs(visit,i,isConnected);
            }
        }
        return p;
    }
};
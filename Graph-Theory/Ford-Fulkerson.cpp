#include<bits/stdc++.h>
using namespace std;

int n;
int capacity[100][100];

int dfs(int curr,int sink,vector<bool> & vis,int flow){
    if(curr == sink) return flow;
    vis[curr] = true;
    for(int nxt = 0; nxt < n; nxt++){
        if(!vis[nxt] && capacity[curr][nxt] > 0){
            int minFlow = dfs(nxt,sink,vis,min(flow,capacity[curr][nxt]));
            if(minFlow > 0){
                capacity[curr][nxt] -= minFlow;
                capacity[nxt][curr]+=minFlow;
                return minFlow;
            }
        }
    }
    return 0;
}
int fordFulkerSon(int src,int sink){
    int maxFlow = 0;
    while(true){
        vector<bool> visited(n,false);
        int flow= dfs(src,sink,visited,INT_MAX);
        maxFlow+= flow;
        if(flow == 0) break;
    }
    return maxFlow;
}
int main(){
    cin >> n ;
    int edges;
    cin >> edges;
    for(int i = 0; i < edges; i++){
        int u,v,c;
        cin >> u >> v >> c;
        capacity[u][v] = c;
    }
    int src ,sink;
    cin >> src >> sink;
    cout << "Maximum Flow " << fordFulkerSon(src,sink);
}
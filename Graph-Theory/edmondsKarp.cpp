#include<bits/stdc++.h>
using namespace std;
int n;
int capacity[100][100];
int bfs(int src,int sink,vector<int> &parent){
    vector<bool> visited(n,false);
    queue<pair<int,int>> q;
    q.push({src,INT_MAX});
    while(!q.empty()){
        auto tp = q.front();
        q.pop();
        int cur = tp.first;
        int flow = tp.second;
        for(int nxt = 0; nxt < n; nxt++){
            if(!visited[nxt] && capacity[cur][nxt] > 0){
                visited[nxt] = true;
                parent[nxt] = cur;
                int newFlow = min(flow,capacity[cur][nxt]);
                if(nxt == sink){
                    return newFlow;
                }
                q.push({nxt,newFlow});
            }
        }
        
    }
    return 0;
}
int edmondKarp(int src,int sink){
    vector<int> parent(n);
    int maxFlow = 0;
    int flow = 0;
    while((flow = bfs(src,sink,parent)) > 0){
        maxFlow+= flow;
        int cur = sink;
        while(cur != src){
            int prev = parent[cur];
            capacity[prev][cur]-=flow;
            capacity[cur][prev]+=flow;
            cur = prev;
        }
    }
    return maxFlow;
}
int main(){
    int edges;
    cin >> n >> edges;
    for(int i = 0; i < edges;i++){
        int u,v,c;
        cin >> u >> v >> c;
        capacity[u][v] = c;
    }
    int src,sink;
    cin >> src >> sink;
    cout << "Maximum Flow : " << edmondKarp(src,sink) << endl;
}
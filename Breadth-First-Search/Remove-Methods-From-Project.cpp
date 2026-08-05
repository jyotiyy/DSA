link: https://leetcode.com/problems/remove-methods-from-project/description/
Restating the given problem , it mentions about removal of suspicious nodes. Where suspicious nodes are the nodes which are derived by kth node
given . However if they are derived from some other non-suspicous nodes they cannot be removed. 

For the question both bfs and dfs are appropriate solutions .In case of BFS , we build an AdjacencyList for all nodes . Also calculate the inDegree 
simultaneously. Now using these 2 we iterated over the Suspicious nodes more specifically . from k using bfs. Finally checking if it was possible 
to remove all suspicious nodes or not suspicious.test(i) && inDegree(i) > 0 

We have used bitset here , cuz it stores only 1 bit for one entry unlike bool which would have taken 4 bytes :(( 
Many insights on the way... ;)

Talking about time Complexity O(V+E);
Space complexity: O(n + m)

----------------- BFS -----------------------------
class Solution {
public:
    static constexpr int MAXN = 100005;
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& inv) {
        vector<vector<int>> edge(n);
        vector<int> inDegree(n,0);

        bitset<MAXN> suspicious; // equivalent to bool suspi[MAXN] , but instead of 4 byte only 1 bit

        for(const auto & in: inv){
            edge[in[0]].push_back(in[1]);
            inDegree[in[1]]++;
        }

        queue<int> q;
        q.push(k);
        suspicious.set(k);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v: edge[u]){
                inDegree[v]--;
                if(!suspicious.test(v)){
                    q.push(v);
                    suspicious.set(v);
                }
            }
        }

        bool canRemoveall = true;
        vector<int> remain;
        for(int i = 0; i < n; i++){
            if(suspicious.test(i) && inDegree[i] > 0){
                canRemoveall = false;
                break;
            }else if(!suspicious.test(i)){
                remain.push_back(i);
            }
        }
        if(!canRemoveall){
            vector<int> allnode(n);
            iota(allnode.begin(),allnode.end(),0);
            return allnode;
        }
        return remain;
    }
};


---------------------------- DFS --------------------------------
class Solution {
public:
    void dfs(int node,unordered_map<int,vector<int>> &inv, vector<int> &vis){
        vis[node] = 1;
        for(auto &it: inv[node]){
            if(!vis[it]){
                dfs(it,inv,vis);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& inv) {
        unordered_map<int,vector<int>> invoke;
        for(auto &it: inv){
            invoke[it[0]].push_back(it[1]);
        }
        vector<int> vis(n,0);
        dfs(k,invoke,vis);

        vector<int> rem;
        for(auto &it: inv){
            if(!vis[it[0]] && vis[it[1]]){ // if a edge goes from non-suspicious to suspiciosus cant be removed sorry:)
                for(int i = 0; i < n; i++){
                    rem.push_back(i);
                }
                return rem;
            }
        }


        for(int i = 0; i < n; i++){
            if(!vis[i]) rem.push_back(i);
        }
        return rem;
    }
};
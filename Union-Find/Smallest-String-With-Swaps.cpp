class Solution {
public:
    vector<int> parent,sz;
    int fp(int u){
        if(parent[u] == u)return u;
        return parent[u] = fp(parent[u]);
    }
    void unite(int u,int v){
        int pu = fp(u);
        int pv = fp(v);
        if(pu == pv)return;
        if(pu<pv){
            swap(pu,pv);
        }
        parent[pv] = pu;
        sz[pu]+=sz[pv];
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        parent.resize(n,0);
        sz.assign(n,1);
        for(int i = 0; i<n;i++){
            parent[i] = i;
        }
        for(auto &p:pairs){
            unite(p[0],p[1]);
        }

        unordered_map<int,vector<int>> mp;
        for(int i = 0; i < n; i++){
            mp[fp(i)].push_back(i);
        }
        for(auto &x: mp){
            vector<int> indices = x.second;
            vector<char> chars;
            for(int x:indices){
                chars.push_back(s[x]);
            }
            sort(chars.begin(),chars.end());
            sort(indices.begin(),indices.end());
            for(int i = 0; i<indices.size(); i++){
                s[indices[i]] = chars[i];
            }
        }
        return s;
    }
};
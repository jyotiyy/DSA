class Solution {
public:
    vector<int> parent;
    int findParent(int u){
        if(parent[u] == u)return u;
        return parent[u] = findParent(parent[u]);
    }
    void unite(int a,int b){
        int pa = findParent(a);
        int pb = findParent(b);
        if(pa == pb)return;
        parent[pb] = pa;
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        for(int i = 0; i< 26; i++){
            parent[i] = i;
        }
        for(string &eq: equations){
            if(eq[1] == '='){
                unite(eq[0]-'a',eq[3]-'a');
            }
        }
        for(string &eq:equations){
            if(eq[1] == '!'){
                if(findParent(eq[0]-'a') == findParent(eq[3]-'a'))return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    //center node will have n-1 in-edges 
    int findCenter(vector<vector<int>>& edges) {
        map<int,int> mp;
        for(vector<int> &x: edges){
            mp[x[0]]++;
            mp[x[1]]++;
            if(mp[x[0]] > 1) return x[0];
            if(mp[x[1]] > 1) return x[1];
        }
        return -1;
    }
};
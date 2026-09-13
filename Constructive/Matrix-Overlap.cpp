The idea is to find the positional pairs with the same distance between them 

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int r = img1.size();
        int c = img1[0].size();
        vector<pair<int,int>> pos1;
        vector<pair<int,int>> pos2;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(img1[i][j] == 1) pos1.push_back({i,j});
                if(img2[i][j] == 1) pos2.push_back({i,j});
            }
        }
        int res = 0;
        map<pair<int,int>,int> trans;
        for(auto &p1: pos1){
            for(auto &p2: pos2){
                int x = p1.first - p2.first;
                int y = p1.second - p2.second;
                trans[{x,y}]++;
                res = max(res,trans[{x,y}]);
            }
        }
        return res;
    }
};
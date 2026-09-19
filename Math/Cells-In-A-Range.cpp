class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> res;
        char c1 = s[0],c2 = s[3],r1 = s[1],r2 = s[4];
        for(int i = c1-'A' ; i <= c2-'A' ;i++){
            string cell(1,'A'+i);
            for(int j = r1-'1' ; j <= r2-'1'; j++){
                res.push_back(cell+(char)(j+'1'));
            }
        }
        return res;
    }
};
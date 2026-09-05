using hash function as sum of ascii values 
inspired by rabin karp
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string pattern = "";
        int curr = 0;
        int tot = 0;
        for(int x: s) tot+=x;
        string sub = "";
        int n = s.size();
        for(int i = 0; i < n; i++){
            curr += s[i];
            sub += s[i];
            if(curr == tot)return false;
            if(tot%curr == 0){
                string p = sub;
                while(p.size()<s.size() && p != s){
                    p += sub;
                }
                if(p == s) return true;
            }
        }
        return false;
        
    }
};
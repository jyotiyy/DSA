class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> pref0(n,0);
        vector<int> suf1(n,0);
        int p = 0;
        int ss = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0')p++;
            if(s[n-i-1] == '1')ss++;
            pref0[i] = p;
            suf1[n-i-1] = ss;
            
        }
        int sc = 0;
        for(int i = 0; i < n-1; i++){
            sc = max(sc,pref0[i]+suf1[i+1]);
        }
        return sc;
    }
};
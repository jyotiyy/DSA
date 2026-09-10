//the most imp idea here is finding the longest palindromic subsequence
//that is basically lcs between a string and its reverse ;)
class Solution {
public:
    int lcs(string &s1,string &s2,vector<vector<int>> &memo,int i,int j){
        if(i == s1.size() || j == s2.size()){
            return 0;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        if(s1[i] == s2[j]){
            return memo[i][j] = lcs(s1,s2,memo,i+1,j+1)+1;
        }
        return memo[i][j] = max(lcs(s1,s2,memo,i+1,j),lcs(s1,s2,memo,i,j+1));

    }
    int minInsertions(string s) {
        int n = s.size();
        string rev = s;
        reverse(rev.begin(),rev.end());
        vector<vector<int>> memo(n,vector<int>(n,-1));
        return n-lcs(s,rev,memo,0,0);
    }
};
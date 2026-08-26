link: https://leetcode.com/problems/di-string-match/description/?envType=problem-list-v2&envId=two-pointers

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int> perm(n+1);
        int left = 0, right = n;
        for(int i = 0; i < n; i++){
            perm[i] = (s[i] == 'I')? left++:right--;
        }
        perm[n] = left;
        return perm;
        

    }
};
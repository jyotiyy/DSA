link: https://leetcode.com/problems/h-index-ii/

Restating the problem , it asks to find the H-index of a person's research work, which is the h value where atleast >= h papers of frequcny  >= h
exists 

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0, r = citations.size()-1;
        while(l <= r){
            int m=l+(r-l)/2;
            if(n-m > citations[m]){
                l = m+1;
            }else{
                r = m-1;
            }
        }
        return n-l;
    }
};
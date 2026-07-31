link: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii

The question is different from part 1 by having multiple occurences of a character in the word .This makes it clear 
to assign number of clicks for a character with more frequency as less 

totalPushes = frequency(char[i]) * (numberofPushes);


class Solution {
public:
    static bool comp(const pair<char,int> &p1,const pair<char,int> &p2){
        return p1.second > p2.second;
    }
    int minimumPushes(string word) {
        map<char,int> fq;
        for(char c: word){
            fq[c]++;
        }
        string dis;
        vector<pair<char,int>> v(fq.begin(),fq.end());
        sort(v.begin(),v.end(),comp);
        for(auto ele: v){
            dis += ele.first;
        }
        int click = 0;
        for(int i = 0; i < dis.size(); i++){
            click += ((i/8)+1)*fq[dis[i]];
        }
        return click;
    }
};
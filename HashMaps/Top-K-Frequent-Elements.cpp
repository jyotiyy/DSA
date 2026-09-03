class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        map<int,int> freq;
        for(int x: nums) freq[x]++;
        vector<pair<int,int>> fq(freq.begin(),freq.end());
        sort(fq.begin(),fq.end(),[](auto &a,auto &b){
            return a.second>b.second;
        });
        for(int i = 0; i < k; i++){
            res.push_back(fq[i].first);
        }
        return res;
        

    }
};
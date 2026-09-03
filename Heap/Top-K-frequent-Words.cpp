class Solution {
public:
    struct cmp{
        bool operator()(const pair<int,string> &p1,const pair<int,string> &p2){
            if(p1.first == p2.first) return p1.second < p2.second;
            return p1.first > p2.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        // For pair<string, int>, C++ compares pairs lexicographically.
        // It first compares the string (first).
        // If the strings are equal, it compares the frequency (second).
        // For a min-heap, use:
        // priority_queue<pair<string, int>,vector<pair<string, int>>,greater<pair<string, int>>> pq;
        map<string,int> m;
        for(string &w:words) m[w]++;
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> pq;
        vector<string> res;
        for(auto &e:m){
            pq.push({e.second,e.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;

    }
};
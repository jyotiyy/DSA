class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){
            return a[0] < b[0];
        });
        vector<vector<int>> merged;
        for(int i = 0; i < n; i++){
            int j = i+1;
            int st = intervals[i][0];
            int en = intervals[i][1];
            while(j < n && (intervals[j][0] <= en)){
                en = max(en,intervals[j][1]);
                j++; 
            }
            merged.push_back({st,en});
            i = j-1;
        }
        return merged;
    }
};
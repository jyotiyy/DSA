class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a)pq.push({a,'a'});
        if(b)pq.push({b,'b'});
        if(c)pq.push({c,'c'});
 
        string res = "";
        while(!pq.empty()){
            pair<int,char> t = pq.top();
            pq.pop();
            int cnt = t.first;
            char ch = t.second;

            if(res.size()>=2 && res[res.size()-1] == ch && res[res.size()-2] == ch){
                if(pq.empty())break;
                pair<int,char> tt = pq.top();
                pq.pop();
                res += tt.second;
                tt.first--;
                if(tt.first){
                    pq.push({tt.first,tt.second});
                }
            }else{
                cnt--;
                res += ch;
            }
            if(cnt) pq.push({cnt,ch});
        }
        return res;

        

    }
};
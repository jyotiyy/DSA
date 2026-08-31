class Solution {
public:
    int fillCups(vector<int>& amount) {
        int res = 0;
        priority_queue<int> pq;
        for(int x:amount){
            if(x) pq.push(x);
        }
        while(!pq.empty()){
            res++;
            int x = pq.top();
            pq.pop();
            if(!pq.empty()){
                int y = pq.top();
                pq.pop();
                if(y-1!=0)pq.push(y-1);
            }
            if(x-1!=0) pq.push(x-1);
        }
        return res;
    }
};
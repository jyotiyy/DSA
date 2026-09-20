//The function that starts first , ends last
class Solution {
public:
    struct Log{
        int id;
        string status;
        int time;
    };
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n);
        stack<Log> st;
        for(string log: logs){
            stringstream ss(log);
            string t1,t2,t3;
            getline(ss,t1,':');
            getline(ss,t2,':');
            getline(ss,t3,':');
            Log lg = {stoi(t1),t2,stoi(t3)};
            if(lg.status == "start"){
                st.push(lg);
            }else{
                assert(st.top().id == lg.id);
                int time_added = lg.time - st.top().time + 1;
                res[lg.id] += time_added;
                st.pop();
                if(!st.empty()){
                    res[st.top().id] -= time_added;
                }
            }


        }
        return res;

    }
};
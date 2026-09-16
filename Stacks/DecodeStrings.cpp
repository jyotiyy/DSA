The idea here was to manipulate the decoding using stack LIFO property , every sub part results to a new string decoded
which is decoded further at upcoming steps 

class Solution {

public:
    string decodeString(string s) {
        string res = "";
        int n = s.size();
        stack<char> st;
        stack<int> fq;
        
        for(int i = 0; i < n; i++){
            if(isdigit(s[i])){
                int x = 0;
                while(isdigit(s[i])){
                    x = x*10 + s[i]-'0';
                    i++;
                }
                fq.push(x);
            }
            if(s[i] != ']'){
                st.push(s[i]);
            }else{
                string sub = "";
                while(st.top() != '['){
                    sub += st.top();
                    st.pop();
                }
                reverse(sub.begin(),sub.end());
                st.pop();
                string temp = "";
                for(int i = 0; i < fq.top(); i++){
                    temp+=sub;
                }
                fq.pop();
                for(char c: temp){
                    st.push(c);
                }
            }
        }
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;

    }
};
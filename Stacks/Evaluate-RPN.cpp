Reverse Polish Notation (RPN), also known as postfix notation, is a mathematical notation in which the operator is written after its operands.

For example:

Infix notation: 3 + 4
Prefix notation: + 3 4
Postfix / RPN: 3 4 +

RPN does not require parentheses because the position of the operators clearly determines the order of operations, as long as each operator has a fixed number of operands.

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int res = 0;
        for(int i = 0; i < tokens.size(); i++){
            string c = tokens[i];
            if(c != "+" && c!="-" && c!= "*" && c!="/"){
                st.push(stoi(c));
            }else{
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                if(c == "+"){
                    st.push(x+y);
                }else if(c == "-"){
                    st.push(y-x);  //important is its y-x not x-y ****
                }else if(c == "*"){
                    st.push(x*y);
                }else{
                    st.push(y/x);
                }
            }
        }
        return st.top();
    }
};
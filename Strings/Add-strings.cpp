class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        int c = 0;
        int i = n1-1,j=n2-1;
        string res = "";
        while(i>=0 || j>=0){
            int sum = c;
            if(i>=0){
                sum+=num1[i]-'0';
                i--;
            }
            if(j>=0){
                sum+=num2[j]-'0';
                j--;
            }
            res = char((sum%10 + '0')) + res;
            c = sum/10;
            
        }
        if(c)res = char(c+'0')+res;
        return res;
        
    }
};
The opposite of Excel sheet column number, here the point i missed was to map 
'A'->'Z' TO 1->26 we need num-- every time 

class Solution {
public:
    string convertToTitle(int num) {
        string ans = "";
        while(num>0){
            num--;
            ans += 'A'+ (char)(num%26);
            num/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
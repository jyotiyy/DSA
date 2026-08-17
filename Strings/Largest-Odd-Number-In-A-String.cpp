link: https://leetcode.com/problems/largest-odd-number-in-string/

The idea is to iterate from last and find the substring ending with an odd digit this will result
to get the longest odd integer substring

class Solution {
public:
    string largestOddNumber(string num) {
        for(int i = num.size()-1; i >= 0; i--){
            if((num[i]-'0')%2 == 1){
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};

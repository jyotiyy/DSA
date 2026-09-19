//Just like how we treat a base number (e.g base 2, base 8, base 16)
//We here have base 26 
//for  CD -> 26^(1)*3 + 26^(0)*4

class Solution {
public:
    int titleToNumber(string title) {
        long long ans = 0;
        //positional value of 26
        //pow(26,pos) + character posn
        for(char c:title){
            ans = ans*26+(c-'A'+1);
        }
        return (int)ans;
    }
};
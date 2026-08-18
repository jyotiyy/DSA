link: https://leetcode.com/problems/count-good-numbers/description/
We are very clear with one thing that if 
n is even -> (5*4)^(n/2)
else (5*4)^(n/2)  * 5
however to fit in constraints we use fast exponentiation 
which says for base , exp 

if exp == 0 return ans 
if exp is odd return power(base,e-1,(ans*b))
if exp is even return ((b*b),e/2,ans);

class Solution {
public:
    int mod = 1e9 + 7;
    //fast exponentiation o(log n)
    long long power(long long b,long long e,long long ans){
        if(e == 0) return ans;
        if(e&1) return power(b,e-1,(ans*b)%mod);
        else return power((b*b)%mod,e/2,ans);
    }
    int countGoodNumbers(long long n) {
        long long temp = power(20,n/2,1);
        return (n&1)? (temp*5)%mod: temp;
    }
};
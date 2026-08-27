link: https://leetcode.com/problems/integer-break/

Whenever you see:

"Break a number into parts to maximize product"
Use as many 3s as possible.
Avoid leaving 1.
Keep 4 as 2*2.
n = 3a + b

If b = 0:
answer = 3^a

If b = 1:
convert one 3+1 into 2+2

If b = 2:
answer = 3^a * 2

 -----------------------------     Euler's method of maximization     -----------------------
 P = (n/x) the number of parts , from here the problem becomes what value of x to maximize the product 
 f(x)=lnP=(xnln)/x​​. Now from here the idea is maximizing f(x), where we get x = e = 2.718 ~ 3

class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        int ans = 1;
        while(n>4){
            ans = ans*3;
            n = n-3;
        }
        return ans*n;
    }
};
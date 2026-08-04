link: https://leetcode.com/problems/sum-of-two-integers/description/

The problem asks for Sum of Two Integers but without the use of + or -
This straight away makes us to consider my personal favourite bit manipulation 

We know that while addition :
1 + 1 = 0 
1 + 0 = 1
0 + 1 = 1
0 + 0 = 0 , This is something same as XOR operation 

Also the carry where created is = a&b
we know it gets added to next imediate position , thus left shift 
carry << 1 = b , and continuing this operation till b disappears gives us the 
final addition 

Sometimes life may humble you in ways just to make you more beileve in yourself :). Far from over 

class Solution {
public:
    int getSum(int a, int b) {
        int carry;
        while(b != 0){
            carry = a&b;
            a = a^b;
            b = (unsigned)carry<<1;
        }
        return a;

    }
};
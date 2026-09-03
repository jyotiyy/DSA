Basically we want atleast some element lesser than an element using which it can come into one of the parity category
fs we cant alter the parity of smallest element so we take that as the 
overall parity and if any hurdle occurs while making the whole array uniform we return false

we know 
 even + even = even 
 odd + odd = even 
 odd + even = odd
 even + odd = odds

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        sort(nums1.begin(),nums1.end());
        bool ae;
        if(nums1[0] % 2) ae = false;
        else ae = true;
        int e = 0,o = 0;
        if(ae) e = 1;
        else o = 1;
        if(ae){
            for(int i = 1; i < n;i++){
                if(nums1[i] % 2 == 1 && o == 0) return false;
                if(nums1[i]%2 == 0)e++;
                else o++;
            }
        }else{
            for(int i = 1; i < n;i++){
                if(nums1[i] % 2 == 0 && o == 0) return false;
                if(nums1[i]%2 == 0)e++;
                else o++;
            }
        }
        return true;
    }
};
Basically the max Replacement in every windo is 
size of window - maxFreq, and for the cases this value is 
> k ,we assume it invalid and move on 

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int freq[26] = {0};

        int mxLen = 0;
        int mxFreq = 0;
        int left = 0;
        int right = 0;
        while(right < n){
            char ch = s[right];
            freq[ch-'A']++;
            mxFreq = max(mxFreq,freq[ch-'A']);
            if((right-left+1)-mxFreq > k){
                freq[s[left]-'A']--;
                left++;
            }
            mxLen = max(mxLen,right-left+1);
            right++;
        }
        return mxLen;
    }
};
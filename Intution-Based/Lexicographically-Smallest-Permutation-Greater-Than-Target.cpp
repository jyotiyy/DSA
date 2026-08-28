link: https://leetcode.com/problems/lexicographically-smallest-permutation-greater-than-target/description/
The idea is very simple considering the lexacographical rules that is 

if a string str1 > str2 , means that till a pivot p str1 is same as str2 
at pivot str1[p] > str2[p] and remaining characters left must be in sorted order for 
smallest possible 

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26,0);
        int n = s.size();
        for(char c: s){
            freq[c-'a']++;
        }
        for(int i = n-1; i >= 0; i--){
            vector<int> remain = freq;
            bool possible = true;
            for(int j = 0; j < i; j++){
                if(remain[target[j]-'a'] == 0){
                    possible = false;
                    break;
                }
                remain[target[j]-'a']--;
            }
            if(!possible){
                continue;
            }
            int targetChar = target[i]-'a'; // we need the smallest possible character here greater than target[i]
            for(int c = targetChar+1; c < 26; c++){
                if(remain[c] == 0)continue;

                string ans = target.substr(0,i);
                ans+= char('a'+c);

                remain[c]--;
                for(int x = 0; x < 26; x++){
                    ans.append(remain[x],char('a'+x));
                }
                return ans;
            }
 
        }

        return "";
    }
};
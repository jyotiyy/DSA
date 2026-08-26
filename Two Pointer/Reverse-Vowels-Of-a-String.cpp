class Solution {
public:
    bool vowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    string reverseVowels(string s) {
      int n = s.size(),i = 0, j = n-1;
      while(i < j){
        while(i<j && i<n&& !vowel(s[i]))i++;
        while(i<j && j >=0 &&!vowel(s[j]))j--;
        if(i == j) break;
        swap(s[i],s[j]);
        i++;
        j--;
      } 
      return s;
    }
};
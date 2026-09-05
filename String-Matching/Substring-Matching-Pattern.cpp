The idea of splitting and matching

class Solution {
public:
    bool hasMatch(string s, string p) {
        int pos = p.find('*');
        string s1,s2;
        s1 = p.substr(0,pos);
        s2 = p.substr(pos+1);
        
        int i = s.find(s1);
        int j = s.find(s2,i+s1.size());
        return i != string::npost && j != string::npos;

    }
};


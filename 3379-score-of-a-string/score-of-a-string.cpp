class Solution {
public:
    int scoreOfString(string s) {
        int sc=0;
        for(int i=0;i<s.size()-1;i++){
            sc+=abs(s[i+1]-s[i]);
        }
        return sc;
    }
};
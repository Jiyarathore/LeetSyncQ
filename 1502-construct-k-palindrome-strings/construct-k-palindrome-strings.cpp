class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length()<k) return false;

        unordered_map<char,int>mp;
        for(char c:s){
            mp[c]++;
        }

        int c=0;
        for(auto& i:mp){
            if(i.second%2!=0) c++;
        }
        return c<=k;
    }
};
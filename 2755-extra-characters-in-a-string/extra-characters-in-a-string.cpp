class Solution {
public:

    int f(int ind, string &s,unordered_map<string, bool>&mp,vector<int>&dp){
        if(ind>=s.size()) return 0;

        if(dp[ind]!=-1) return dp[ind];

        string curr="";
        int mini=s.size();
        for(int i=ind;i<s.size();i++){
            curr.push_back(s[i]);
            int extraCount=curr.size();

            if(mp[curr]) extraCount=0;

            extraCount+=f(i+1, s, mp, dp);
            mini=min(mini,extraCount);
        }
        return dp[ind]=mini;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string, bool>mp;
        for(auto& word:dictionary){
            mp[word]=true;
        }
        vector<int>dp(s.size(),-1);

        return f(0,s,mp,dp);
    }
};
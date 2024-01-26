class Solution {
public:

    bool solve(int startInd, string s,  unordered_set<string>&dict, vector<int>&dp){
        if(startInd==s.size()) return true;
        if(dp[startInd]!=-1) return dp[startInd];

        for(int i=startInd;i<s.size();i++){
            if(dict.count(s.substr(startInd, i-startInd+1)) && solve(i+1, s, dict, dp)){
                dp[startInd]=1;
                return true;
            }
        }
        return dp[startInd]=false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dict(wordDict.begin(), wordDict.end());
        vector<int>dp(s.size(),-1);
        return solve(0, s, dict, dp);
    }
};
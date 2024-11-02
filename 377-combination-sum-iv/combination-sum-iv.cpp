class Solution {
public:

    int f(vector<int>&dp, vector<int>&nums, int t){
        if(t<0) return 0;
        if(dp[t]!=-1) return dp[t];
        if(t==0) return 1;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=f(dp,nums, t-nums[i]);
        }
        return dp[t]=ans;

    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        return f(dp,nums,target);
       
    }
};
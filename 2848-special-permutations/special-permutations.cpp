class Solution {
public:

    int mod=1000000007;

    int solve(int i1, int n, vector<bool>&v, vector<int>&nums, int arraysize, int prev, int uniquecomb, vector<vector<int>>&dp){
        if(arraysize==n) return 1;

        if(dp[prev+1][uniquecomb]!=-1) return dp[prev+1][uniquecomb];

        long long c=0;
        for(int i=0;i<n;i++){
            if(!v[i]){
                int t;
                if(prev==-1) t=1;
                else t=nums[prev];

                if(nums[i]%t==0 || t%nums[i]==0){
                    v[i]=true;
                    c+=(solve(0,n,v,nums,arraysize+1,i,uniquecomb+pow(2,i),dp))%mod;
                    v[i]=false;
                }
            }
        }
        return dp[prev+1][uniquecomb]=c%mod;
    }

    int specialPerm(vector<int>& nums) {
        int n=nums.size();
        vector<bool>v(n,false);
        vector<vector<int>>dp(15,vector<int>(pow(2,16), -1));
        return solve(0,n,v,nums,0,-1,0,dp)%mod;
    }
};
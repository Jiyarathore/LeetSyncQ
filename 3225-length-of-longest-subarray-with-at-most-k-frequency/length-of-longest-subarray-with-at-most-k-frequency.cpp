class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int>m;
        int start=0,end=0;
        int ans=0;
        
        while(end<nums.size()){
            if(m[nums[end]]<k){
                m[nums[end]]++;
                end++;
            }
            else{
                m[nums[start]]--;
                start++;
            }
            ans=max(ans, end-start);
        }
        return ans;
    }
};
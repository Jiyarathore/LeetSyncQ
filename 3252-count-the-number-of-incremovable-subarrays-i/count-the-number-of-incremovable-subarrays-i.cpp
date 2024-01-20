class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n=nums.size();
        int result=0;
        for(int l=0;l<n;l++){
            for(int r=l;r<n;r++){
                if(check(nums,l,r)) result++;
            }
        }
        return result;
    }

    bool check(vector<int>&nums, int l ,int r){
        int n=nums.size();
        int prev=INT_MIN;
        for(int i=0;i<n;i++){
            if((l<=i) && (i<=r)) continue;
            if(prev>=nums[i]) return false;
            prev=nums[i];
        }
        return true;
    }
};
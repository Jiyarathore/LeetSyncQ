class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>m;
        int sum=0;
        int l=0;
        for(int i=0;i<n;i++){
            sum+=nums[i]==0?-1:1;
            if(sum==0){
                l=i+1;
            }
            else if(m.find(sum)!=m.end()){
                l=max(l,i-m[sum]);
            }
            else{
                m[sum]=i;
            }
        }
        return l;
    }
};
class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long c=0;
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHp;

        for(int i=0;i<n;i++){
            minHp.push({nums[i],i});
        }

        while(!minHp.empty()){
            auto curr=minHp.top();
            minHp.pop();
            int num=curr.first;
            int ind=curr.second;

            if(nums[ind]!=-1){
                c+=nums[ind];
                nums[ind]=-1;
                if(ind>0 && nums[ind-1]!=-1){
                    nums[ind-1]=-1;
                }
                if(ind<n-1 && nums[ind+1]!=-1){
                    nums[ind+1]=-1;
                }
            }
        }
        return c;

    }
};
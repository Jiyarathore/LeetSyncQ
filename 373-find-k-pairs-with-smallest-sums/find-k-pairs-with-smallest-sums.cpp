class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>ans;
        int n=nums1.size();
         priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>pq;

        for(int i=0;i<min(k,n);i++){
            pq.push({nums1[i]+nums2[0],{i,0}});
        }

        int c=0;
        while(!pq.empty() && c<k){
            int sum=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();

            ans.push_back({nums1[i],nums2[j]});
            int nex=j+1;
            if(nums2.size()>nex){
                pq.push({nums1[i]+nums2[nex],{i,nex}});
            }
            c++;
        }
            return ans;
    }
};
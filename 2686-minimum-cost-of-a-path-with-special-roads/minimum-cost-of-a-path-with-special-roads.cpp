class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        const int INF=1e9+10;
        int n=specialRoads.size();

        vector<int>d(n,INF);

       priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

       for(int i=0;i<n;i++){
           d[i]=abs(start[0]-specialRoads[i][0]) + abs(start[1] - specialRoads[i][1]) + specialRoads[i][4];
           pq.push({d[i],i});
       }

       int ans=abs(start[0]-target[0])+ abs(start[1]-target[1]);

       while(pq.size()){
           auto [dp,p]=pq.top();
           pq.pop();

           if(dp!=d[p]) continue;

           ans=min(ans, dp+ abs(target[0]-specialRoads[p][2]) + abs(target[1] - specialRoads[p][3]));

           for(int nxt=0;nxt<n;nxt++){
               int w=abs(specialRoads[p][2] - specialRoads[nxt][0]) + abs(specialRoads[p][3] - specialRoads[nxt][1]) + specialRoads[nxt][4];
               if(dp + w < d[nxt]){
                   d[nxt]=dp+w;
                   pq.push({d[nxt],nxt});
               }
           }
       }
       return ans;
    }
};
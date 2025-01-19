class Solution {
public:
    int trapRainWater(vector<vector<int>>& hMap) {
        int n=hMap.size();
        int m=hMap[0].size();

        priority_queue<pair<int,pair<int,int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int,int>>>>pq;

        vector<vector<int>>vis(n,vector<int>(m));

        for(int i=0;i<n;i++){
            vis[i][0]=1;
            vis[i][m-1]=1;

            pq.push({hMap[i][0], {i,0}});
            pq.push({hMap[i][m-1], {i,m-1}});
        }

        for(int i=0;i<m;i++){
            vis[0][i]=1;
            vis[n-1][i]=1;

            pq.push({hMap[0][i], {0,i}});
            pq.push({hMap[n-1][i], {n-1,i}});
        }

        int ans=0;
        while(!pq.empty()){
            int h=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();

            int dr[4]={0,0,-1,1};
            int dc[4]={-1,1,0,0};

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    ans+=max(0,h-hMap[nr][nc]);
                    pq.push({max(h, hMap[nr][nc]), {nr,nc}});
                }
            }
        }
        return ans;
    }
};
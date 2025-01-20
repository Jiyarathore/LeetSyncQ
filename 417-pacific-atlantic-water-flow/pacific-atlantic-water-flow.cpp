class Solution {
public:

    void bfs(int n, int m, vector<vector<bool>>&vis, queue<pair<int,int>>&q, vector<vector<int>>& heights){
        vector<int>dr={0,0,-1,1};
        vector<int>dc={-1,1,0,0};

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            vis[r][c]=true;

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0 && nc>=0 && nr<n && nc<m && heights[r][c]<=heights[nr][nc] && !vis[nr][nc]){
                    q.push({nr,nc});
                }
            }

        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>ans;
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<bool>>pac(n,vector<bool>(m));
        vector<vector<bool>>atl(n,vector<bool>(m));
        queue<pair<int,int>>q;

        for(int i=n-1;i>=0;i--) q.push({i,0});
        for(int i=m-1;i>=0;i--) q.push({0,i});

        bfs(n,m,pac, q,heights);

        for(int i=n-1;i>=0;i--) q.push({i,m-1});
        for(int i=m-1;i>=0;i--) q.push({n-1,i});

        bfs(n,m,atl,q,heights);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(atl[i][j] && pac[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
        
    }
};
class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int maxi=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              if(grid[i][j]>0){
               int ct=0;
              queue<pair<int,int>>q;
              q.push({i,j});

              while(!q.empty()){
                int r=q.front().first;
                int c=q.front().second;

                q.pop();

                if(grid[r][c]>0){
                    ct+=grid[r][c];
                    grid[r][c]=0;

                    if(r>0 && grid[r-1][c]>0) q.push({r-1,c});
                    if (r + 1 < n && grid[r + 1][c] > 0) q.push({r + 1, c});
                    if (c > 0 && grid[r][c - 1] > 0) q.push({r, c - 1});
                    if (c + 1 < m && grid[r][c + 1] > 0) q.push({r,  c + 1});
                }
              }
              maxi=max(maxi,ct);               

            }
        }
        }
        return maxi;


    }
};
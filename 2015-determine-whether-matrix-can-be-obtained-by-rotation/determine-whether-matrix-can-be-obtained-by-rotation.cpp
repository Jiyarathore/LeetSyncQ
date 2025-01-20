class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int deg=3;
        int n=mat.size();
        if(mat==target) return true;

        while(deg--){
            for(int i=0;i<n;i++){
                for(int j=i;j<n;j++){
                    swap(mat[i][j],mat[j][i]);
                }
            }

            for(int i=0;i<n;i++){
                reverse(mat[i].begin(),mat[i].end());
            }
            if(mat==target) return true;
        }
        return false;
    
    }
};
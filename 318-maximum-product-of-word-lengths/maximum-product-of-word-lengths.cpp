class Solution {
public:

    bool checkCommonCh(vector<int>&a, vector<int>&b){
        for(int i=0;i<26;i++){
            if(a[i]>0 && b[i]>0) return true;
        }
        return false;
    }
    int maxProduct(vector<string>& words) {
        int n=words.size();
        int r=0;
        vector<vector<int>>v(n,vector<int>(26,0));
        for(int i=0;i<n;i++){
            for(auto ch:words[i]){
                v[i][ch-'a']++;
            }

            for(int j=0;j<i;j++){
                if(!checkCommonCh(v[i],v[j])){
                    int s=words[i].size() * words[j].size();
                    r=max(r,s);
                }
            }
        }
        return r;
    }
};
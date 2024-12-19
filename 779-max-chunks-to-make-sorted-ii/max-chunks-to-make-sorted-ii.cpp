class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int>v=arr;
        sort(v.begin(),v.end());
        long long int c=0,s1=0,s2=0;
        for(int i=0;i<arr.size();i++){
            s1+=arr[i];
            s2+=v[i];
            if(s1==s2)c++;
        }
        return c;
    }
};
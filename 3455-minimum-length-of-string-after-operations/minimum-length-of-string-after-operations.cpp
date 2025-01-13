class Solution {
public:
    int minimumLength(string s) {
        vector<int>v(26,0);
        int l=0;
        for(char ch:s){
            v[ch-'a']++;
        }
        for(int freq:v){
            if(freq==0) continue;
            if(freq%2==0){ l+=2;}
            else{
                l+=1;
            }
        }
        return l;
    }
};
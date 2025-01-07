class Solution {
public:
    void prec(vector<string>& words, vector<vector<int>>&lps){
        for(string word:words){
            int n=word.size();

            vector<int>wlps(n);

            int i=1,j=0;
            while(i<n){
                if(word[i]==word[j]){
                    wlps[i]=j+1;
                    i++;
                    j++;
                }
                else if(j>0){
                    j=wlps[j-1];
                }
                else{
                    i++;
                }
            }
            lps.push_back(wlps);
        }
    }

    bool f(string& pat, vector<int>&lps, string &text){
        int ps=pat.size();
        int ts=text.size();
        int i=0,j=0;

        while(i<ps && j<ts){
            if(pat[i]==text[j]){
                i++;
                j++;
            }
            if(i==ps) return true;

            if(j<ts && pat[i]!=text[j]){
                if(i>0){
                    i=lps[i-1];
                }
                else{
                    j++;
                }
            }
        }
        return false;
    }

    static bool comp(string& a, string& b){
        return a.size()<=b.size();
    }
    vector<string> stringMatching(vector<string>& words) {
        int n=words.size();

        sort(words.begin(),words.end(),comp);
        vector<vector<int>>lps;
        prec(words,lps);

        vector<string>res;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(f(words[i],lps[i],words[j])){
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};
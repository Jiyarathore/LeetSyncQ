class Solution {
public:
    static bool compare(string& first, string& second){
        return first.size()>second.size();
    }

    int minimumLengthEncoding(vector<string>& words) {
        unordered_map<string, int>mp;
        int ans=0;

        sort(words.begin(), words.end(), compare);

        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }

        // for each word if it exist in hashmap then add its lenght+1
        for(int i=0;i<words.size();i++){
            int k=words[i].size();
            if(mp[words[i]]>0){
                ans+=(k+1);
            }

            // deleting record of any sufix of word from hashmap

            for(int j=k-1;j>=0;j--){
                string s=words[i].substr(j,k-j);
                mp[s]=0;
            }
        }
        return ans;
    }
};
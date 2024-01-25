class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>m;
        for(auto i:words){
            m[i]++;
        }
        vector<string>ans;
        
       vector<pair<string, int>>v;
       for(auto i:m){
           v.push_back(i);
       }

       auto cmp = [&](auto &a, auto &b){
           if(a.second==b.second){
               return a.first<b.first;
           }
           return a.second>b.second;
       };

       sort(v.begin(), v.end(), cmp);

       for(auto i:v){
           ans.push_back(i.first);
           k--;
           if(k==0){
               break;
           }
       }
       return ans;
    }
};
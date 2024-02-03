class Solution {
public:

    bool isSubsequence(string sub, string super){
        int i=0,j=0;
        while(i<sub.size() && j<super.size()){
            if(sub[i]==super[j]){
                i++;
                j++;
            }
            else j++;
        }
        return i==sub.size();
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        string ans="";

        for(string& word:dictionary){
            if(word.size()>ans.size() || (word.size()==ans.size() && word<ans)){
                if(isSubsequence(word,s)){
                    ans=word;
                }
            }
        }
        return ans;
    }
};
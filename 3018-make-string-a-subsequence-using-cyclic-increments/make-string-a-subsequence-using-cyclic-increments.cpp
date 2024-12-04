class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int s1len=str1.size();
        int s2len=str2.size();
        int s1Ind=0,s2Ind=0;

        while(s1Ind<s1len && s2Ind<s2len){
            if((str1[s1Ind]==str2[s2Ind]) || (str1[s1Ind]=='z' && str2[s2Ind]=='a') || (str1[s1Ind] +1 ==str2[s2Ind])){
                s1Ind++;
                s2Ind++;
            }
            else{
                s1Ind++;
            }
        }
        return s2Ind==s2len;

    }
};
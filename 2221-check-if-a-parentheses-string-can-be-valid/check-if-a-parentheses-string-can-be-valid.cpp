class Solution {
public:
    bool canBeValid(string s, string locked) {
        int len=s.length();
        if(len%2==1) return false;

        stack<int>openInd;
        stack<int>unlockedInd;

        for(int i=0;i<len;i++){
            if(locked[i]=='0'){
                unlockedInd.push(i);
            }
            else if(s[i]=='('){
                openInd.push(i);
            }
            else if(s[i]==')'){
                if(!openInd.empty()){
                    openInd.pop();
                }
                else if(!unlockedInd.empty()){
                    unlockedInd.pop();
                }
                else{
                    return false;
                }
            }
        }

        while(!openInd.empty() && !unlockedInd.empty() && openInd.top()<unlockedInd.top()){
            openInd.pop();
            unlockedInd.pop();
        }

        if(openInd.empty() && !unlockedInd.empty()){
            return unlockedInd.size()%2==0;
        }
        return openInd.empty();
    }
};
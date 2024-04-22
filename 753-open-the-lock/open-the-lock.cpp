class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>deadendSet(deadends.begin(), deadends.end());
        if(deadendSet.count("0000")){
            return -1;
        }
        queue<pair<string, int>>q;
        q.push({"0000",0});
        unordered_set<string>visited;
        visited.insert("0000");

        while(!q.empty()){
            auto current = q.front();
            q.pop();
            string currentComb = current.first;
            int moves = current.second;

            if(currentComb == target){
                return moves;
            }

            for(int i=0;i<4;i++){
                for(int delta: {-1,1}){
                    int newDigit = (currentComb[i] - '0' + delta + 10)%10;
                    string newComb = currentComb;
                    newComb[i]= '0' + newDigit;

                    if (visited.find(newComb) == visited.end() && deadendSet.find(newComb) == deadendSet.end()) {
                        visited.insert(newComb);
                        q.push({newComb, moves + 1});
                    }
                }
            }
        }
        return -1;
    }
};
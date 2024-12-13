class Solution {
public:
    int f(int x){
        int c=0;
        while(x!=1){

        if(x%2==0){
            x=x/2;
        }
        else{
            x=3*x+1;
        }
        c++;
        }
        return c;
    }
    int getKth(int lo, int hi, int k) {
       
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>minHp;
        for(int i=lo;i<=hi;i++){
            int p=f(i);
            minHp.push({p,i});
        }
        k--;
        while(!minHp.empty() && k>0){
            minHp.pop();
            k--;
        }
        return minHp.top().second;
    }
};
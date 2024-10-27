class Solution {
public:
    const int mod=1337;

    int pow(int a, int b){
        int ans=1;
        a%=mod;
        for(int i=0;i<b;i++){
            ans=(ans*a)%mod;
        }
        return ans;
    }
    int superPow(int a, vector<int>& b) {
        int ans=1;
        for(int i=b.size()-1;i>=0;i--){
            ans=(ans*pow(a,b[i]))%mod;
            a=pow(a,10);
        }
        return ans;
    }
};
class Solution {
public:
    string toHex(int num) {
        string hex="0123456789abcdef";

        if(num==0) return "0";
        if(num>0 && num<15) return string(1,hex[num]);

        unsigned int n=num;

        string res="";
        while(n>0){
            res=hex[n%16]+res;
            n=n/16;
        }
        return res;
    }
};
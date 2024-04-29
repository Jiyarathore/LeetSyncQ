class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int finalXor=0;
        for(int i:nums){
            finalXor=finalXor^i;
        }

        int c=0;

        while(k|| finalXor){
            if((k%2)!=(finalXor%2)){
                c++;
            }

            k/=2;
            finalXor/=2;
        }
        return c;
    }
};
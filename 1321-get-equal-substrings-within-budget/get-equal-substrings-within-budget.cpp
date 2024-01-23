class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left=0, right=0, curr_cost=0, maxi=0 ,n=s.size();

        for(int right=0;right<n;right++){
            curr_cost+=abs(s[right]-t[right]);

            while(left<=right && curr_cost>maxCost){
                curr_cost-=abs(s[left]-t[left]);
                left++;
            }

            maxi=max(maxi, right-left+1);
        }
        return maxi;
    }
};
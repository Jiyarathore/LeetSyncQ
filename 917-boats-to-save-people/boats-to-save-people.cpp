class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int sum=0,c=0;
        int l=0,r=people.size()-1;

        while(l<=r){
            if(people[l]+people[r]<=limit){
                l++;
                r--;
            }
            else{
                r--;
            }
            c++;
        }
        return c;
    }
};
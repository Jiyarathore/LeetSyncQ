class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] ans={-1,-1};
        boolean findStartIndex=true;
        int start = bs(nums, target, findStartIndex);
        int end = bs(nums, target, !findStartIndex);

        ans[0]=start;
        ans[1]=end;

        return ans;
    }

   int bs(int[] nums, int target, boolean findStartIndex){
        int ans=-1, start=0, end=nums.length -1;
        while(start<=end){
            int mid=start + (end-start)/2;

            if(target < nums[mid]){
                end=mid-1;
            }
            else if (target > nums[mid]){
                start=mid+1;
            }
            else{
                ans=mid;
                if(findStartIndex==true){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
        }
        return ans;
    }

}
class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int start =0, end=arr.length -1;
        while(start<end){
            int mid=start + (end-start)/2;

            if(arr[mid] > arr[mid+1]){
                // desc order
                end=mid;
            }
            else{
                // asc order
                start = mid + 1;
            }

        }
        return start;
    }
}
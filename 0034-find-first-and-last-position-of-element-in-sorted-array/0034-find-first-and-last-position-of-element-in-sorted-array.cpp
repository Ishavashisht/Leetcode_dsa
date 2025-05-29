class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       auto lower_bound = [](vector<int>& nums, int target) {
        int low=0,high=nums.size();
        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[mid]<target){
             low=mid+1;

            }
            else{
                high=mid;
            }
        }
        return low;
       };
       auto upper_bound = [](vector<int>& nums, int target) {
        int low=0,high=nums.size();
        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[mid]<=target){
             low=mid+1;

            }
            else{
                high=mid;
            }
        }
        return low;
       };
       int start=lower_bound(nums,target);
       int end=upper_bound(nums,target)-1;
       if(start<=end && start<nums.size() && nums[start]==target && nums[end]==target){
        return {start,end};

       }
       else{
        return {-1,-1};
       }
    }
};
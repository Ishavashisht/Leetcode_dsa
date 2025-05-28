class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
      
        // if(nums.size()==1&&nums[0]==target){
        //     return 0;
        // }
       
        while(left<=right){
             int mid=(left+right)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]<target){
           left= mid+1;
        }
        else{
        right=mid-1;
        }
       
        }
        return -1;
    }
};
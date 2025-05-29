class Solution {
public:
    bool check(vector<int>&nums,int k,int maxSum){
        int currSum=0;
        int splits=1;
        for(int num:nums){
           if(currSum+num>maxSum){
            splits++;//start new array
            currSum=num;//restart curr sum
            if(splits>k)return false;
        }
        else{
            currSum+=num;
        }  
    }
    return true;
    }
    int splitArray(vector<int>& nums, int k) {
       int low=*max_element(nums.begin(),nums.end());
     
       int high=accumulate(nums.begin(),nums.end(),0);
         int largestSum=high;
       while(low<=high){
        int mid=low+(high-low)/2;
      
        if(check(nums,k,mid)){
            largestSum=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
       }
       return largestSum;
    }
};
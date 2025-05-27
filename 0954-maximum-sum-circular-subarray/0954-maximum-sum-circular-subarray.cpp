class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
       int n=nums.size();
      int maxsum=nums[0],currmaxSum=nums[0];
       for(int i=1;i<n;i++){
        currmaxSum=max(nums[i],currmaxSum+nums[i]);
        maxsum=max(maxsum,currmaxSum);
       }
       int minsum=nums[0],currminSum=nums[0],total=nums[0];
       for(int i=1;i<n;i++){
         total += nums[i];
        currminSum=min(nums[i],currminSum+nums[i]);
        minsum=min(minsum,currminSum);
       }
        int circularSum = total - minsum;
     if (maxsum < 0) return maxsum;
     else
     return max(circularSum,maxsum);
    }
};
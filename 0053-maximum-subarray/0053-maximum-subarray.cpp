class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxSum=nums[0],curr=nums[0];
for(int i=1;i<n;i++){
curr=max(nums[i],curr+nums[i]);
maxSum=max(maxSum,curr);
}
return maxSum;
    }
};
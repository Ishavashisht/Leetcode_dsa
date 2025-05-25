class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
    int n=nums.size();
    if(n<k)return 0;
    int currSum=0;
    int maxSum=INT_MIN;
    for(int i=0;i<k;i++){
currSum+=nums[i];
    }
    maxSum=currSum;
    for(int i=k;i<n;i++){
        currSum+=nums[i]-nums[i-k];
        maxSum=max(maxSum,currSum);
    }
    return (double)maxSum/k;
    }
};
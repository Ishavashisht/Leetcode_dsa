class Solution {
public:
    int solve(vector<int>&nums,int target,int i, map<pair<int,int>,int>&dp){
        if(i>=nums.size())return target==0;
     if(dp.find({target,i})!=dp.end())return dp[{target,i}];
        int way1=solve(nums,target-nums[i],i+1,dp);
        int way2=solve(nums,target+nums[i],i+1,dp);
        return dp[{target,i}]=way1+way2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
    map<pair<int,int>,int>dp;
        return solve(nums,target,0,dp);
    }
};
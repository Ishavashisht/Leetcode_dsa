class Solution {
public:
    int solve(vector<int>&nums,int target,int i){
        if(i==nums.size())return target==0;
        int plus=solve(nums,target-nums[i],i+1);//num ka sign + liya h 
        int minus=solve(nums,target+nums[i],i+1);
        return plus+minus;
    }
    int solve_Mem(vector<int>&nums,int target,int i,map<pair<int,int>,int>&dp){
        if(i==nums.size())return target==0?1:0;
        if(dp.find({i,target})!=dp.end())return dp[{i,target}];
        int plus=solve_Mem(nums,target-nums[i],i+1,dp);//num ka sign + liya h 
        int minus=solve_Mem(nums,target+nums[i],i+1,dp);
        return dp[{i,target}]=plus+minus;
    }
    int solve_Tabulation(vector<int>&nums,int target){
        map<pair<int,int>,int>dp;
        dp[{nums.size(),0}]=1;//sab traverse kr liya h 
        int total=0;
        for(auto num:nums) total+=num;
        for(int i=nums.size()-1;i>=0;--i){
         for(int sum=-total;sum<=total;++sum){
          
         int plus=dp.find({i+1,sum-nums[i]})!=dp.end()?dp[{i+1,sum-nums[i]}]:0;//num ka sign + liya h 
        int minus=dp.find({i+1,sum+nums[i]})!=dp.end()?dp[{i+1,sum+nums[i]}]:0;
         dp[{i,sum}]=plus+minus;
        }
        }
         // Return the number of ways to achieve the target sum starting from index 0
    // return dp.find({0, target}) != dp.end() ? dp[{0, target}] : 0;

        return dp[{0,target}];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // return solve(nums,target,0);
       // map<pair<int,int>,int>dp;//{i,target}=> no of ways
        // return solve_Mem(nums,target,0,dp);
        return solve_Tabulation(nums,target);
    }
};
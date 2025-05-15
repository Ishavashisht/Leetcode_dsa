class Solution {
public:
    int solveMem(vector<int>&nums,int i,int n,vector<int>&dp){
        
        if(i>=n){return 0;}
        if(dp[i]!=-1){return dp[i];}
        
        int include=nums[i]+solveMem(nums,i+2,n,dp);
        int exclude=solveMem(nums,i+1,n,dp);
        dp[i]=max(include,exclude);
        
        
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solveMem(nums,0,n,dp);

    }
};
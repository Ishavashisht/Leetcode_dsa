class Solution {
public:
    int solveMem(vector<int>&nums,int i,int j,vector<int>&dp){
        if(i>j)return 0;
        if(dp[i]!=-1)return dp[i];
        int opt1=nums[i]+solveMem(nums,i+2,j,dp);
        int opt2=0+solveMem(nums,i+1,j,dp);
        dp[i]=max(opt1,opt2);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        vector<int>dp1(nums.size(),-1),dp2(nums.size(),-1);
        int n=nums.size();
        if(n==1)return nums[0];
        int opt1=solveMem(nums,0,n-2,dp1);
        int opt2=solveMem(nums,1,n-1,dp2);
        return max(opt1,opt2);

    }
};
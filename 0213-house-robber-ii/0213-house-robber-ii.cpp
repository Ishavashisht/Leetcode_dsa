class Solution {
public:



int solve(vector<int>&nums,int s,int e){
    //base case 
    if(s>e){
        return 0;

    }
    //chori karlo-> ith index pr
    int option1=nums[s]+solve(nums,s+2,e);
    //chori mat karlo->ith index pr
    int option2=0+solve(nums,s+1,e);
    int finalAns=max(option1,option2);
    return finalAns;

}
int solveMem(vector<int>&nums,int i,int j,vector<vector<int>>&dp){
    if(i>j){
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int opt1=nums[i]+solveMem(nums,i+2,j,dp);
    int opt2=solveMem(nums,i+1,j,dp);
    int ans=max(opt1,opt2);
    dp[i][j]=ans;
    return dp[i][j];
}
    int rob(vector<int>& nums) {
        int size=nums.size();
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        //single wala case-----galati thi
        if(size==1){
            return nums[0];
        }
     
        int option1=solveMem(nums,0,size-2,dp);
        int option2=solveMem(nums,1,size-1,dp);
        int ans=max(option1,option2);
        return ans; 
    }
};
 
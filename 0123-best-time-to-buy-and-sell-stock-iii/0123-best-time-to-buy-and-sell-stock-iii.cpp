class Solution {
public:
int solve(vector<int>&prices,int i,int buy,int limit,vector<vector<vector<int>>>&dp){
    if(i>=prices.size()||limit==0)return 0;
     if(dp[i][buy][limit]!=-1)return dp[i][buy][limit];
    int profit=0;
    if(buy){
        int p1=-prices[i]+solve(prices,i+1,0,limit,dp);
        int p2=solve(prices,i+1,1,limit,dp);
        profit=max(p1,p2);
    }
    else
   { int sell=prices[i]+solve(prices,i+1,1,limit-1,dp);
    int ignore=solve(prices,i+1,0,limit,dp);
    profit=max(sell,ignore);}
    return dp[i][buy][limit]=profit;

   }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,0,1,2,dp);
    }
};
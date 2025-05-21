class Solution {
public:
   int solve(vector<int>&prices,int i,int buy, vector<vector<int>>&dp){
    if(i>=prices.size())return 0;
    if(dp[i][buy]!=-1)return dp[i][buy];
    int profit=0;
    if(buy){
        int p1=-prices[i]+solve(prices,i+1,0,dp);
        int p2=solve(prices,i+1,1,dp);
        profit=max(p1,p2);
    }
    else
   { int sell=prices[i]+solve(prices,i+1,1,dp);
    int ignore=solve(prices,i+1,0,dp);
    profit=max(sell,ignore);}
    return dp[i][buy]=profit;

   }
    int maxProfit(vector<int>& prices) {
        //buy -1
        //sell =0
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        return solve(prices,0,1,dp);
    }
};
class Solution {
public:
    int solve(vector<int>& coins, int amount){
     if(amount==0)return 0;
     int mini=INT_MAX;
     int ans=INT_MAX;
     for(int i=0;i<coins.size();i++){
        int coin=coins[i];
        if(coin<=amount){
            
            int recAns=solve(coins,amount-coin);

        
        if(recAns!=INT_MAX){
            int ans=1+recAns;
            mini=min(ans,mini);
        }
     }
     }
     return mini;
    }
    int solveMem(vector<int>&coins,int amount,vector<int>&dp){
       
        if(amount==0)return 0;
        if (amount < 0) return INT_MAX;
         int mini=INT_MAX;
        int ans=INT_MAX;
        if(dp[amount]!=-1)return dp[amount];
    for(int i=0;i<coins.size();i++){
        if(coins[i]<=amount){
            int recAns=solveMem(coins,amount-coins[i],dp);
            if(recAns!=INT_MAX){
                ans=1+recAns;
                mini=min(ans,mini);
            }
        }
      
    }
      dp[amount]=mini;
    return dp[amount];

    }
 int solveUsingTab(vector<int>&coins,int amount){
    vector<int>dp(amount+1,INT_MAX);
    dp[0]=0;
     int mini=INT_MAX;
     int ans=INT_MAX;
 for (int i = 1; i <= amount; ++i) {
        for (int j = 0; j < coins.size(); ++j) {
            int coin = coins[j];
            if (coin <= i && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1); // Update the dp array
            }
        }
    }
    
    // If dp[amount] is still INT_MAX, it means we can't make that amount
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}
    
    int coinChange(vector<int>&coins,int amount){
        // int ans=solve(coins,amount);
        vector<int>dp(amount+1,-1);
        int res=solveMem(coins,amount,dp);
        return (res==INT_MAX)?-1:res;
    //    return solveUsingTab(coins,amount);
    //     if(ans==INT_MAX){
    //         return -1;
    //     }
    //     else 
    //     return ans;
    }
};
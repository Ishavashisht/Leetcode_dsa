class Solution {
public:
int M=1e9+7;
   int solve(int n,int num,int x,vector<vector<long long>>&dp){
    if(n==0)return 1;
   
    if(n<0)return 0;
long long currPower = pow(num,x);

    if(currPower>n){
        return 0;
    }
    if(dp[n][num]!=-1)return dp[n][num];
    long long take=solve(n-currPower,num+1,x,dp);
    long long skip=solve(n,num+1,x,dp);
    return dp[n][num]=(take+skip)%M;
   }
    int numberOfWays(int n, int x) {
        vector<vector<long long>>dp(n+1,vector<long long>(n+1,-1));

        int ans=solve(n,1,x,dp);
        return ans;
    }
};
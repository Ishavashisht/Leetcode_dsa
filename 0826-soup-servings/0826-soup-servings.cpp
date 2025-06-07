class Solution {
public:
   
        double dfs(int a,int b,vector<vector<double>>&dp){
if(a<=0 && b<=0)return 0.5;
if(a<=0 )return 1.0;
if(b<=0)return 0;
if(dp[a][b]>=0)return dp[a][b];
dp[a][b]=0.25*(dfs(a-4,b,dp)+	
	dfs(a-3,b-1,dp)+
	dfs(a-2,b-2,dp)+
	dfs(a-1,b-3,dp)
);
return dp[a][b];
}

double soupServings(int n){
if(n>4800)return 1.0;
int N=(n+24)/25;
vector<vector<double>>dp(N+1,vector<double>(N+1,-1.0));
return dfs(N,N,dp);

    }
};
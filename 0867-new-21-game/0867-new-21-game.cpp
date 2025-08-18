class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k==0 ||n>=k+maxPts-1)return 1.0;
      vector<double>dp(n+maxPts+1,0.0);
for(int i=k;i<=n;i++){
dp[i]=1.0;
}
        double windowSum=n-k+1;
for(int x=k-1;x>=0;--x){
dp[x]=windowSum/maxPts;
windowSum+=dp[x]-dp[x+maxPts];
}
return dp[0];
    }
};
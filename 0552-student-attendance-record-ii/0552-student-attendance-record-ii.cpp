class Solution {
public:
int const MOD=1000000007;
    int checkRecord(int n) {
        if(n==0)return 1;
vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
dp[0][0][0]=1;
for(int i=1;i<=n;i++){
for(int a=0;a<=1;a++){
for(int l=0;l<=2;l++){
int currCount=dp[i-1][a][l];
if(currCount==0)continue;
dp[i][a][0]=(dp[i][a][0]+currCount)%MOD;
if(l<2){
dp[i][a][l+1]=(dp[i][a][l+1]+currCount)%MOD;
}
if(a<1){
dp[i][a+1][0]=(dp[i][a+1][0]+currCount)%MOD;
}}}}
int res=0;
for(int a=0;a<=1;a++){
for(int l=0;l<=2;l++){
res=(res+dp[n][a][l])%MOD;
}}
return res;

    }
};
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
       vector<vector<double>>dp(query_row+2,vector<double>(query_row+2,0.0));

dp[0][0]=poured;

for(int row=0;row<=query_row;++row){
for(int col=0;col<=row;++col){
double overflow=max(0.0,(dp[row][col]-1.0)/2.0);
if(overflow>0){
dp[row+1][col]+=overflow;
dp[row+1][col+1]+=overflow;
}
}
}
return min(1.0,dp[query_row][query_glass]);
 
    }
};
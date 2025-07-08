class Solution {
public:
    int solve(int i,int j,string text1,string text2,vector<vector<int>>&dp){
        int n=text1.length(),m=text2.length();
        if(i>=n)return 0;
        if(j>=m)return 0;
if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        
                if(text1[i]==text2[j]){
                  ans=1+solve(i+1,j+1,text1,text2,dp);
                  

                }
                else {
                  ans=0+max(solve(i+1,j,text1,text2,dp),solve(i,j+1,text1,text2,dp));
                }
         
       dp[i][j]= ans;
       return dp[i][j];
    }

     int solveUsingTabulation(string a,string b){
    vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1,0));
    for(int i_index=a.length()-1;i_index>=0;i_index--){
        for(int j_index=b.length()-1;j_index>=0;j_index--){
         int ans = 0;
        if(a[i_index] == b[j_index]) {
            ans = 1 +dp[i_index+1][j_index+1];
        }
        else {
            ans = 0 + max(dp[i_index][j_index+1],
                        dp[i_index+1][j_index]);
        }
        dp[i_index][j_index] = ans;
        }
    }
    return dp[0][0];
 }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
    //     vector<vector<int>>dp(n,vector<int>(m,-1));
    //    return  solve(0,0,text1,text2,dp);
    return solveUsingTabulation(text1,text2);
    }
};
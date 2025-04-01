class Solution {
public:
int n;
   long long solve(int i,vector<vector<int>>& questions){
    if(i>=n)return 0;
    long long taken=questions[i][0]+solve(i+(questions[i][1]+1),questions);
    long long non_taken=solve(i+1,questions);
    return max(taken,non_taken);
   }
   long long solveMem(int i,vector<vector<int>>&questions, vector<long long>&dp){
     if(i>=n)return 0;
    if(dp[i]!=-1)return dp[i];
long long taken=questions[i][0]+solveMem(i+(questions[i][1]+1),questions,dp);
    long long non_taken=solveMem(i+1,questions,dp);
    dp[i]=max(taken,non_taken);
    return dp[i];
   }
    long long mostPoints(vector<vector<int>>& questions) {
        n=questions.size();
        vector<long long>dp(n+1,-1);
        return solveMem(0,questions,dp);
    }
};
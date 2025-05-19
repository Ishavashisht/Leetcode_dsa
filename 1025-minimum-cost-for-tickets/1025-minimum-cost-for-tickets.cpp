class Solution {
public:
    int solve(vector<int>&days,vector<int>&costs,int i,vector<int>&dp){
     if(i>=days.size())return 0;
     if(dp[i]!=-1)return dp[i];
    //1 day
    int cost1=costs[0]+solve(days,costs,i+1,dp);
    //7 day pass taken 
    int passEndday=days[i]+7-1;
    int j=i;
    while(j<days.size() && days[j]<=passEndday){
        j++;}
    int cost7=costs[1]+solve(days,costs,j,dp);
    //30 days pass taken 
    passEndday=days[i]+30-1;
     j=i;
    while(j<days.size() && days[j]<=passEndday){
        j++;}
    int cost30=costs[2]+solve(days,costs,j,dp);
    dp[i]=min(cost1,min(cost7,cost30));
    return dp[i];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n+1,-1);
       return solve(days,costs,0,dp); 
    }
};
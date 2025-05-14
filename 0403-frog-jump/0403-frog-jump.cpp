class Solution {
public:
   int n;
   unordered_map<int,int>mp;
    // int solve(vector<int>&stones,int curr_stone_idx,int prevjump){
        
    //     if(curr_stone_idx==n-1)return true;
    //     bool res=false;
    //     for(int nextjump=prevjump-1;nextjump<=prevjump+1;nextjump++){
    //     if(nextjump>0){
    //     int nextstone=stones[curr_stone_idx]+nextjump;
    //     if(mp.find(nextstone)!=mp.end()){
    //          res||solve(stones,mp[nextstone],nextjump);
    //     }
    //     }
    //     }
    //     return res;
    // }
    int solveMem(vector<int>&stones,int curr_stone_index,int prevjump,vector<vector<int>>&dp){
        if(curr_stone_index==n-1)return true;
      if (dp[curr_stone_index][prevjump] != -1) return dp[curr_stone_index][prevjump];
        bool res=false;
        for(int nxtjump=prevjump-1;nxtjump<=prevjump+1;nxtjump++){
if(nxtjump>0){
   int nextstone=stones[ curr_stone_index]+nxtjump;
        if(mp.find(nextstone)!=mp.end()){
             res=res||solveMem(stones,mp[nextstone],nxtjump,dp);
        }
        }
        }
        return dp[curr_stone_index][prevjump]=res;
    }
    bool canCross(vector<int>& stones) {
     n=stones.size();
     vector<vector<int>>dp(n,vector<int>(n,-1));
        if(stones[1]!=1){
            return false;
        }
        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }
        return solveMem(stones,0,0,dp);
    }
};
class Solution {
public:
//approch1 
    bool check(string &s,int i,int j){
        if(i>j){
            return true;
        }
        if(s[i]==s[j]){
            return check(s,i+1,j-1);
        }
        return false;
    }
    //approach2
     bool checkMem(string &s,int i,int j,vector<vector<int>>&dp){
        if(i>j){
            return true;
        }
       if(dp[i][j]!=-1)return dp[i][j];

        if(s[i]==s[j]){
          dp[i][j]= checkMem(s,i+1,j-1,dp);
          return dp[i][j];
           
        }
        return dp[i][j]=false;
    }
    //approach3 
    int solveTab(string s){
        int n=s.length();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        int count=0;
        for(int L=1;L<=n;L++){
        for(int i=0;i+L-1<n;i++){
            int j=i+L-1;
            if(i==j){
                //one length
                dp[i][j]=true;
            }
          else if(i+1==j){
            //length 2 
            dp[i][j]=(s[i]==s[j]);
          }
          else {
            dp[i][j]=(s[i]==s[j]&& dp[i+1][j-1]);
          }
          if(dp[i][j]==true){
            count++;
          }
        }
        }
        return count;
    }
    //approach 4 
    //using even and odd length 
    int count;
    void checkEO(string &s,int i,int j,int n){
     
        while(i>=0 && j<n && s[i]==s[j]){
            count++;
            i--;//left 
            j++;
        }
    }
    int countSubstrings(string s) {
        int n=s.length();
    //     vector<vector<int>>dp(n,vector<int>(n,-1));
      count=0;
    //     for(int i=0;i<n;i++){
    //         for(int j=i;j<n;j++){
    //             //explore all the possible cases and then check them'
    //             // if(check(s,i,j,dp)){
    //                 if(checkMem(s,i,j,dp)){
    //                 count++;
    //             }
    //         }
    //     }
    //     return count;
    // }
    // return solveTab(s);
    //apprach 4 
    for(int i=0;i<n;i++){
        checkEO(s,i,i,n);
        checkEO(s,i,i+1,n);
    }
    return count;
    }
};
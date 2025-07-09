class Solution {
public:
// int solve(string &a ,string & b,int i,int j){
//     //base case 
//     if(i>=a.length()){
//         //word1 wali string end ho gyi
//         //yani word1 ki lenght mau be word 2 se choti h

//         return b.length()-j;

//     }
//     if(j>=b.length()){
//         //word 2 end hogaya 
//         // yaani word 1 ki length may be freater than wordds haai 
//         return a.length()-i;
//     }
//     int ans=0;
//     if(a[i]==b[j]){
//         //match
//         ans=0+solve(a,b,i+1,j+1);
//     }
//     else {
//         //not mathc 
//         //operatio  perform karo 
//         //insert
//         int option1=1+solve(a,b,i,j+1);
//         //remove 
//         int option2=1+solve(a,b,i+1,j);
//         //replace 
//         int option3=1+solve(a,b,i+1,j+1);
//         ans=min(option1,min(option2,option3));

//     }
//     return ans ;
    //}
    int solveUsingRecursion(string& a,string& b,int i,int j){
        //base case 
        if(i==a.length()){
            return b.length()-j;

        }
        if(j==b.length()){
            return a.length()-i;
        }
        int ans=0;
        if(a[i]==b[j]){
            ans=0+solveUsingRecursion(a,b,i+1,j+1);
        }
        else{
            int replace=1+solveUsingRecursion(a,b,i+1,j+1);
            int insert=1+solveUsingRecursion(a,b,i,j+1);
            int remove=1+solveUsingRecursion(a,b,i+1,j);
            ans=min(insert,min(remove,replace));

        }
        return ans;
    }
    int solveUsingMem(string& a,string& b,int i,int j,vector<vector<int> >&dp){
        if(i==a.length()){
            return b.length()-j;

        }
        if(j==b.length()){
            return a.length()-i;
        }
        //check if already exist 
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(a[i]==b[j]){
            ans=0+solveUsingMem(a,b,i+1,j+1,dp);
        }
        else{
            int replace=1+solveUsingMem(a,b,i+1,j+1,dp);
            int insert=1+solveUsingMem(a,b,i,j+1,dp);
            int remove=1+solveUsingMem(a,b,i+1,j,dp);
            ans=min(insert,min(remove,replace));

        }
        dp[i][j]=ans;
        return dp[i][j];
    }
    int solveUsingTabulation(string a,string b){
        vector<vector<int> >dp(a.length()+1,vector<int>(b.length()+1,-1));
        for(int col=0;col<=b.length();col++){
            dp[a.length()][col]=b.length()-col;
        }
        for(int row=0;row<=a.length();row++ ){
            dp[row][b.length()]=a.length()-row;
        }
        //ulta chala do 
        for(int i_index=a.length()-1;i_index>=0;i_index--){
            for(int j_index=b.length()-1;j_index>=0;j_index--){
               int ans=0;
               if(a[i_index]==b[j_index]){
                   ans=0+dp[i_index+1][j_index+1];
        }
        else{
            int replace=1+dp[i_index+1][j_index+1];
            int insert=1+dp[i_index][j_index+1];
            int remove=1+dp[i_index+1][j_index];
            ans=min(insert,min(remove,replace));

        }
        dp[i_index][j_index]=ans;
            }
        }
        return dp[0][0];
    }
    int solveUsingTabulationSO(string a,string b){
       // vector<vector<int> >dp(a.length()+1,vector<int>(b.length()+1,-1));
        vector<int>curr(a.length()+1,0);
        vector<int>next(a.length()+1,0);
        //abhi k liye bhul jao 
        // for(int col=0;col<=b.length();col++){
        //     dp[a.length()][col]=b.length()-col;
        // }
        for(int row=0;row<=a.length();row++ ){
           next[row]=a.length()-row;
        }
        //ulta chala do 
        for(int j_index=b.length()-1;j_index>=0;j_index--){
        for(int i_index=a.length()-1;i_index>=0;i_index--){
            
               int ans=0;
               if(a[i_index]==b[j_index]){
                   ans=0+next[i_index+1];
        }
        else{
            int replace=1+next[i_index+1];
            int insert=1+next[i_index];
            int remove=1+curr[i_index+1];
            ans=min(insert,min(remove,replace));

        }
        curr[i_index]=ans;
            }
            //shifting 
            next=curr;
        }
        return next[0];
    }
    int minDistance(string word1, string word2) {
        int i=0;
        int j=0;
        // int ans=solve(word1,word2,i,j);
        //vector<vector<int> >dp(word1.length()+1,vector<int>(word2.length()+1,-1));
        // int ans=solveUsingRecursion(word1,word2,i,j); 
       // int ans=solveUsingMem(word1,word2,i,j,dp); 
          int ans=solveUsingTabulation(word1,word2);
        return ans;
    }
};
class Solution {
public:
   int dfs(vector<vector<int>>& matrix,int i,int j, vector<vector<int>>&dp,vector<vector<int>>&directions){
    
    if(dp[i][j]!=-1)return dp[i][j];
    int m=matrix.size();
    int n=matrix[0].size();
    int maxPath=1;
    for(auto&dir:directions){
        int x=i+dir[0];
        int y=j+dir[1];

    
    if(x>=0 && x<m && y<n && y>=0 && matrix[x][y]>matrix[i][j]){
        maxPath=max(maxPath,1+dfs(matrix,x,y,dp,directions));
    }
    }
    return dp[i][j]=maxPath;
   }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        vector<vector<int>>directions={{-1,0},{1,0},{0,-1},{0,1}};
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res=max(res,dfs(matrix,i,j,dp,directions));
            }
        }
        return res;
    }
};
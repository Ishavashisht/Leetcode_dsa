class Solution {
public:
//    int solve(int i,int j,vector<vector<int>>&triangle,int n){
//     if(i==n-1)return triangle[n-1][j];
//     int down=triangle[i][j]+solve(i+1,j,triangle,n);
//     int diagonal=triangle[i][j]+solve(i+1,j+1,triangle,n);
//     return min(down,diagonal);
//    }
//    int solveMemo(int i,int j,vector<vector<int>>&triangle,int n,vector<vector<int>>&dp){
//     if(i==n-1)return triangle[n-1][j];
//     if(dp[i][j]!=-1)return dp[i][j];
//     int down=triangle[i][j]+solveMemo(i+1,j,triangle,n,dp);
//     int diagonal=triangle[i][j]+solveMemo(i+1,j+1,triangle,n,dp);
//     return dp[i][j]=min(down,diagonal);
//    }
    int minimumTotal(vector<vector<int>>& triangle) {
       for (int i = triangle.size() - 2; i >= 0; i--)
            for (int j = 0; j < triangle[i].size(); j++)
                triangle[i][j] +=
                    min(triangle[i + 1][j], triangle[i + 1][j + 1]);

        return triangle[0][0];
    }
};
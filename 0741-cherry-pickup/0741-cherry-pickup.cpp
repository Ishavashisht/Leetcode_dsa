class Solution {
public:
    int solve(vector<vector<int>>&grid,int r1,int c1,int r2,vector<vector<vector<int>>>&dp){
        int n=grid.size();
        int c2=r1+c1-r2;
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return INT_MIN;
        }
 if (r1 == n - 1 && c1 == n - 1) {
            return grid[r1][c1]; // Only one cell to pick
        }
        
        if(dp[r1][c1][r2]!=-1){
            return dp[r1][c1][r2];
        }
        int cheeries=0;
        if(r1==r2 && c1==c2){
            cheeries+=grid[r1][c1];
        }
        else{
            cheeries+=grid[r1][c1]+grid[r2][c2];
        }
        int maxCherries = max({
            solve(grid, r1 + 1, c1, r2 + 1, dp), // Both move down
            solve(grid, r1, c1 + 1, r2, dp),     // Both move right
            solve(grid, r1 + 1, c1, r2, dp),     // First moves down, second moves right
            solve(grid, r1, c1 + 1, r2 + 1, dp)  // First moves right, second moves down
        });
        cheeries+=maxCherries;
        return dp[r1][c1][r2]=cheeries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
               vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
      return max(0,solve(grid,0,0,0,dp));

    }
};
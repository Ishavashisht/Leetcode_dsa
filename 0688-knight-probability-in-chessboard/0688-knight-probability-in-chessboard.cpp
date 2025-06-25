class Solution {
public:
    vector<vector<vector<double>>> dp;
    vector<pair<int, int>> directions = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };

    
    double dfs(int n, int k, int row, int col) { 
       
        if (row < 0 || row >= n || col < 0 || col >= n) return 0.0;

        
        if (k == 0) return 1.0;

       
        if (dp[k][row][col] != -1.0) return dp[k][row][col];

        
        double prob = 0;

        
        for (auto& [dx, dy] : directions) {
            int newRow = row + dx;    
            int newCol = col + dy;
            prob += dfs(n, k - 1, newRow, newCol) / 8.0;
        }

      
        return dp[k][row][col] = prob;
    }

    double knightProbability(int n, int k, int row, int column) {
       
        dp = vector<vector<vector<double>>>(k + 1, vector<vector<double>>(n, vector<double>(n, -1.0)));
        
        return dfs(n, k, row, column);
    }
};

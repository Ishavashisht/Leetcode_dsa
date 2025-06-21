class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& vis, int i, int j) {
        int m = board.size();
        int n = board[0].size();
        
        
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O' || vis[i][j]) return;
        
        // Mark as visited
        vis[i][j] = true;
        
        // Explore all 4 directions
        dfs(board, vis, i - 1, j); // Up
        dfs(board, vis, i + 1, j); // Down
        dfs(board, vis, i, j - 1); // Left
        dfs(board, vis, i, j + 1); // Right
    }
    
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;

        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        // Perform DFS for all 'O's on the boundary
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O' && !vis[i][0]) dfs(board, vis, i, 0);       // Left boundary
            if (board[i][n - 1] == 'O' && !vis[i][n - 1]) dfs(board, vis, i, n - 1); // Right boundary
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O' && !vis[0][j]) dfs(board, vis, 0, j);       // Top boundary
            if (board[m - 1][j] == 'O' && !vis[m - 1][j]) dfs(board, vis, m - 1, j); // Bottom boundary
        }

        // Flip all unvisited 'O' to 'X'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

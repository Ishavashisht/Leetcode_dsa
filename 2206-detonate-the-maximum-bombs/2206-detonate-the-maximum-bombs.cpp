class Solution {
public:
    // DFS function to count how many bombs can be detonated from a given starting bomb
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, int& count) {
        visited[node] = true;
        count++; // Increment the count of detonated bombs

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, graph, visited, count);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n);

        // Build the directed graph
        for (int i = 0; i < n; i++) {
            long long xi = bombs[i][0], yi = bombs[i][1], ri = bombs[i][2];
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                long long xj = bombs[j][0], yj = bombs[j][1];
                long long dx = xi - xj;
                long long dy = yi - yj;
                long long distSq = dx * dx + dy * dy;

                if (distSq <= ri * ri) {
                    graph[i].push_back(j); // i can detonate j
                }
            }
        }

        int maxDetonated = 0;

        // Try to start the detonation from every bomb
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            int count = 0;
            dfs(i, graph, visited, count);
            maxDetonated = max(maxDetonated, count);
        }

        return maxDetonated;
    }
};

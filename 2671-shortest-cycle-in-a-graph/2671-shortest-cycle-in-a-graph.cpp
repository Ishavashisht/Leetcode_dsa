class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int minCycle = INT_MAX;

        for (int start = 0; start < n; ++start) {
            vector<int> dist(n, -1); 
            vector<int> parent(n, -1);
            queue<int> q;

            dist[start] = 0;
            q.push(start);

            while (!q.empty()) {
                int node = q.front(); q.pop();

                for (int neighbor : adj[node]) {
                    if (dist[neighbor] == -1) {
                        dist[neighbor] = dist[node] + 1;
                        parent[neighbor] = node;
                        q.push(neighbor);
                    } else if (parent[node] != neighbor) {
                        
                        int cycleLen = dist[node] + dist[neighbor] + 1;
                        minCycle = min(minCycle, cycleLen);
                    }
                }
            }
        }

        return (minCycle == INT_MAX) ? -1 : minCycle;
    }
};

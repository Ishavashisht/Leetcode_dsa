
 class Solution {
public:
    unordered_map<int, stack<pair<int, int>>> adj;
    vector<int> result;

    void dfs(int node) {
        auto& stackRef = adj[node];
        while (!stackRef.empty()) {
            auto [nextNode, pairIndex] = stackRef.top();
            stackRef.pop();
            dfs(nextNode);
            result.push_back(pairIndex);
        }
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n = pairs.size();
        unordered_map<int, int> indegree, outdegree;

        // Build the graph
        for (int i = 0; i < n; i++) {
            int u = pairs[i][0];
            int v = pairs[i][1];
            outdegree[u]++;
            indegree[v]++;
            adj[u].push({v, i});
        }

        // Find start node
        int start = pairs[0][0];
        for (auto& [node, outdeg] : outdegree) {
            if (outdeg > indegree[node]) {
                start = node;
                break;
            }
        }

        // Perform DFS
        dfs(start);

        // Build result
        reverse(result.begin(), result.end());
        vector<vector<int>> finalResult;
        for (int idx : result) {
            finalResult.push_back(pairs[idx]);
        }

        return finalResult;
    }
};

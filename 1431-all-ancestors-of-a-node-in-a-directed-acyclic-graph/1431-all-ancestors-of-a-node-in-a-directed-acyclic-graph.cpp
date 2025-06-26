class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n); 
        vector<int> indegree(n, 0); 
        
        
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

       
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

      
        vector<set<int>> ancestors(n);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                
                ancestors[neighbor].insert(node);
                ancestors[neighbor].insert(ancestors[node].begin(), ancestors[node].end());

              
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

       
        vector<vector<int>> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
        }

        return result;
    }
};

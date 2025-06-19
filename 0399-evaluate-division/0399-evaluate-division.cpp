class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;

    double dfs(string curr, string target, unordered_set<string>& visited, double product) {
        if (curr == target) return product;
        visited.insert(curr);

        for (auto& neighbor : graph[curr]) {
            string nextnode = neighbor.first;
            double weight = neighbor.second;
            if (visited.find(nextnode) == visited.end()) {  // corrected this line
                double result = dfs(nextnode, target, visited, product * weight);
                if (result != -1.0) return result;
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Build graph
        for (int i = 0; i < equations.size(); i++) {   // removed extra semicolon here
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            graph[u].push_back({v, val});
            graph[v].push_back({u, 1.0 / val});
        }

        vector<double> results;

        for (auto& query : queries) {
            string start = query[0];
            string end = query[1];

            if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) {
                results.push_back(-1.0);
            }
            else if (start == end) {
                results.push_back(1.0);
            }
            else {
                unordered_set<string> visited;
                double res = dfs(start, end, visited, 1.0);
                results.push_back(res);
            }
        }

        return results;
    }
};

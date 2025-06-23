class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>>adj;
        if(source==target)return 0;
        for(int i=0;i<routes.size();i++){
            for(int stops:routes[i]){
                adj[stops].push_back(i);
            }
        }
       queue<int> q;
vector<bool> visited(routes.size(), false);
for (int route : adj[source]) {
    q.push(route);
    visited[route] = true;
}
int busCount = 1;

while (!q.empty()) {
    int sz = q.size();
    while (sz--) {
        int route = q.front(); q.pop();
        for (int stop : routes[route]) {
            if (stop == target) return busCount;
            for (int nextRoute : adj[stop]) {
                if (!visited[nextRoute]) {
                    visited[nextRoute] = true;
                    q.push(nextRoute);
                }
            }
        }
    }
    busCount++;
}
return -1;
    }
};
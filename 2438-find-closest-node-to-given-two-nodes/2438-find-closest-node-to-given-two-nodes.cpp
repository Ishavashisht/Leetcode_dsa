class Solution {
public:
void calculateDistances(const vector<int>& edges, int startNode, vector<int>& distances) {
    queue<int> q;
    q.push(startNode);
    distances[startNode] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        int neighbor = edges[current];
        if (neighbor != -1 && distances[neighbor] == INT_MAX) {
            distances[neighbor] = distances[current] + 1;
            q.push(neighbor);
        }
    }
}

int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    int n = edges.size();
    vector<int> dist1(n, INT_MAX), dist2(n, INT_MAX);

    // Calculate distances from node1 and node2
    calculateDistances(edges, node1, dist1);
    calculateDistances(edges, node2, dist2);

    // Find the closest node
    int minDistance = INT_MAX, result = -1;
    for (int i = 0; i < n; i++) {
        if (dist1[i] != INT_MAX && dist2[i] != INT_MAX) {
            int maxDistance = max(dist1[i], dist2[i]);
            if (maxDistance < minDistance || (maxDistance == minDistance && i < result)) {
                minDistance = maxDistance;
                result = i;
            }
        }
    }

    return result;
}
};
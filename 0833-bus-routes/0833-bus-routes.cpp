class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        // Map each stop to the list of buses (indices) that serve it
        unordered_map<int, vector<int>> stop_to_buses;
        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i]) {
                stop_to_buses[stop].push_back(i);
            }
        }

        // BFS queue initialized with the source stop
        queue<int> q;
        q.push(source);

        // Track visited stops and buses to prevent redundant processing
        unordered_set<int> visited_stops;
        unordered_set<int> visited_buses;
        visited_stops.insert(source);

        int buses_taken = 0;

        while (!q.empty()) {
            buses_taken++;
            int size = q.size();

            while (size--) {
                int stop = q.front(); q.pop();

                // Visit each bus that stops here
                for (int bus : stop_to_buses[stop]) {
                    if (visited_buses.count(bus)) continue;
                    visited_buses.insert(bus);

                    // Explore all stops on this bus route
                    for (int next_stop : routes[bus]) {
                        if (next_stop == target)
                            return buses_taken;

                        if (!visited_stops.count(next_stop)) {
                            visited_stops.insert(next_stop);
                            q.push(next_stop);
                        }
                    }
                }
            }
        }

        return -1;
    }
};

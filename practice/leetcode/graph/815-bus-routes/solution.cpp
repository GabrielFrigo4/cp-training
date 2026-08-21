class Solution {
private:
    int bfs(unordered_map<int, vector<int>>& graph, vector<vector<int>>& routes, int source, int target) {
        unordered_set<int> used;
        queue<int> next;
        for (int route : graph[source]) {
            next.push(route);
            used.insert(route);
        }

        int buses = 1;
        while (!next.empty()) {
            for (int size = next.size(); size > 0; size--) {
                int route = next.front();
                next.pop();

                for (int stop : routes[route]) {
                    if (stop == target) {
                        return buses;
                    }

                    for (int next_route : graph[stop]) {
                        if (used.contains(next_route)) {
                            continue;
                        }
                        next.push(next_route);
                        used.insert(next_route);
                    }
                }
            }
            buses++;
        }

        return -1;
    }
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }

        unordered_map<int, vector<int>> graph;
        for (int route = 0; route < routes.size(); route++) {
            for (int stop : routes[route]) {
                graph[stop].push_back(route);
            }
        }

        return bfs(graph, routes, source, target);
    }
};

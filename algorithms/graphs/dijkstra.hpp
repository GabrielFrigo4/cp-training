#pragma once
#include <vector>
#include <queue>
#include <utility>
#include <cstdint>

template <typename T = int64_t>
std::vector<T> dijkstra(int source, int n, const std::vector<std::vector<std::pair<int, T>>>& adj, T INF = 1e18) {
    std::vector<T> dist(n, INF);
    std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<>> pq;

    dist[source] = 0;
    pq.emplace(0, source);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    return dist;
}

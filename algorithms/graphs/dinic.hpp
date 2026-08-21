#pragma once
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdint>

template <typename Flow = int64_t>
struct Dinic {
    struct Edge {
        int to;
        Flow cap, flow;
        int rev;
    };

    int n, src, dst;
    std::vector<std::vector<Edge>> adj;
    std::vector<int> level, ptr;

    Dinic(int n, int src, int dst) : n(n), src(src), dst(dst), adj(n), level(n), ptr(n) {}

    void add_edge(int from, int to, Flow cap) {
        adj[from].push_back({to, cap, 0, (int)adj[to].size()});
        adj[to].push_back({from, 0, 0, (int)adj[from].size() - 1});
    }

    bool bfs() {
        std::fill(level.begin(), level.end(), -1);
        level[src] = 0;
        std::queue<int> q;
        q.push(src);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto& edge : adj[v]) {
                if (edge.cap - edge.flow > 0 && level[edge.to] == -1) {
                    level[edge.to] = level[v] + 1;
                    q.push(edge.to);
                }
            }
        }
        return level[dst] != -1;
    }

    Flow dfs(int v, Flow pushed) {
        if (pushed == 0 || v == dst) return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); ++cid) {
            auto& edge = adj[v][cid];
            int tr = edge.to;
            if (level[v] + 1 != level[tr] || edge.cap - edge.flow == 0) continue;
            Flow tr_flow = dfs(tr, std::min(pushed, edge.cap - edge.flow));
            if (tr_flow == 0) continue;
            edge.flow += tr_flow;
            adj[tr][edge.rev].flow -= tr_flow;
            return tr_flow;
        }
        return 0;
    }

    Flow max_flow() {
        Flow flow = 0;
        while (bfs()) {
            std::fill(ptr.begin(), ptr.end(), 0);
            while (Flow pushed = dfs(src, 1e18)) {
                flow += pushed;
            }
        }
        return flow;
    }
};

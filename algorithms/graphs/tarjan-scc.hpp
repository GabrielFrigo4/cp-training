#pragma once
#include <vector>
#include <stack>
#include <algorithm>

struct TarjanSCC {
    int n, timer = 0, scc_count = 0;
    std::vector<std::vector<int>> adj;
    std::vector<int> tin, low, comp;
    std::vector<bool> in_stack;
    std::stack<int> st;

    explicit TarjanSCC(int n) : n(n), adj(n), tin(n, -1), low(n, -1), comp(n, -1), in_stack(n, false) {}

    void add_edge(int u, int v) { adj[u].push_back(v); }

    void dfs(int u) {
        tin[u] = low[u] = ++timer;
        st.push(u);
        in_stack[u] = true;

        for (int v : adj[u]) {
            if (tin[v] == -1) {
                dfs(v);
                low[u] = std::min(low[u], low[v]);
            } else if (in_stack[v]) {
                low[u] = std::min(low[u], tin[v]);
            }
        }

        if (low[u] == tin[u]) {
            while (true) {
                int v = st.top();
                st.pop();
                in_stack[v] = false;
                comp[v] = scc_count;
                if (u == v) break;
            }
            scc_count++;
        }
    }

    void build() {
        for (int i = 0; i < n; ++i) {
            if (tin[i] == -1) dfs(i);
        }
    }
};

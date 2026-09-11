// ==============================================================================
// Competitive Programming Hub - Automated Algorithms Compilation & Sanity Test
// ==============================================================================

#include <iostream>
#include <vector>
#include <cassert>
#include <string>

// Data Structures
#include "../algorithms/data-structures/dsu.hpp"
#include "../algorithms/data-structures/fenwick-tree.hpp"
#include "../algorithms/data-structures/segment-tree.hpp"
#include "../algorithms/data-structures/sparse-table.hpp"

// Graphs
#include "../algorithms/graphs/dijkstra.hpp"
#include "../algorithms/graphs/dinic.hpp"
#include "../algorithms/graphs/tarjan-scc.hpp"

// Math & Number Theory
#include "../algorithms/math/sieve.hpp"
#include "../algorithms/math/combinatorics.hpp"
#include "../algorithms/math/fast-pow.hpp"

// Strings & Geometry
#include "../algorithms/strings/kmp.hpp"
#include "../algorithms/geometry/point2d.hpp"

// Dynamic Programming
#include "../algorithms/dynamic-programming/lis.hpp"

int main() {
    std::cout << "[Test Algorithms] Iniciando testes dos componentes modulares...\n";

    // 1. Teste DSU
    {
        DSU dsu(5);
        assert(!dsu.same(0, 1));
        dsu.merge(0, 1);
        assert(dsu.same(0, 1));
        assert(dsu.size(0) == 2);
    }

    // 2. Teste Fenwick Tree
    {
        FenwickTree<int64_t> ft(5);
        ft.add(0, 10);
        ft.add(1, 20);
        assert(ft.query(0, 1) == 30);
        assert(ft.query(1, 1) == 20);
    }

    // 3. Teste Segment Tree
    {
        std::vector<int> a = {1, 3, 2, 7, 9, 11};
        SegmentTree<int> st((int)a.size(), 0, [](int x, int y) { return x + y; });
        st.build(a, 1, 0, (int)a.size() - 1);
        assert(st.query(1, 0, (int)a.size() - 1, 0, 2) == 6);
    }

    // 4. Teste Sparse Table
    {
        std::vector<int> a = {5, 2, 4, 7, 1, 8};
        SparseTable<int> spt(a);
        assert(spt.query_min(0, 2) == 2);
        assert(spt.query_min(0, 5) == 1);
    }

    // 5. Teste Dijkstra
    {
        int n = 3;
        std::vector<std::vector<std::pair<int, int64_t>>> adj(n);
        adj[0].push_back({1, 5});
        adj[1].push_back({2, 3});
        adj[0].push_back({2, 10});
        auto dist = dijkstra(0, n, adj);
        assert(dist[2] == 8);
    }

    // 6. Teste Dinic Max Flow
    {
        Dinic<int64_t> dinic(4, 0, 3);
        dinic.add_edge(0, 1, 10);
        dinic.add_edge(1, 3, 5);
        dinic.add_edge(0, 2, 10);
        dinic.add_edge(2, 3, 8);
        assert(dinic.max_flow() == 13);
    }

    // 7. Teste Tarjan SCC
    {
        TarjanSCC scc(3);
        scc.add_edge(0, 1);
        scc.add_edge(1, 2);
        scc.add_edge(2, 0);
        scc.build();
        assert(scc.scc_count == 1);
    }

    // 8. Teste Linear Sieve
    {
        LinearSieve sieve(30);
        assert(sieve.is_prime(2));
        assert(sieve.is_prime(29));
        assert(!sieve.is_prime(4));
        assert(!sieve.is_prime(1));
    }

    // 9. Teste Combinatorics & Fast Pow
    {
        Combinatorics comb(100, 1000000007);
        assert(comb.nCr(5, 2) == 10);
        assert(comb.nPr(5, 2) == 20);
        assert(power(2, 10, 1000000007) == 1024);
    }

    // 10. Teste KMP
    {
        std::string text = "ababcabcabababd";
        std::string pattern = "ababd";
        auto matches = kmp_match(text, pattern);
        assert(matches.size() == 1);
        assert(matches[0] == 10);
    }

    // 11. Teste Point2D
    {
        Point<double> p1(0, 0), p2(3, 4);
        assert((p2 - p1).dist() == 5.0);
        assert(p1.dot(p2) == 0.0);
    }

    // 12. Teste LIS
    {
        std::vector<int> a = {10, 9, 2, 5, 3, 7, 101, 18};
        assert(longest_increasing_subsequence(a) == 4);
    }

    std::cout << "[Test Algorithms] ✔ Todos os 12 algoritmos modulares foram compilados e validados com sucesso!\n";
    return 0;
}

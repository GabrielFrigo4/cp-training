import sys

class DSU:
    def __init__(self, n):
        self.parent = list(range(n + 1))
        self.size = [1] * (n + 1)
        
    def find(self, i):
        path = []
        while self.parent[i] != i:
            path.append(i)
            i = self.parent[i]
        for node in path:
            self.parent[node] = i
        return i
        
    def union(self, i, j):
        root_i = self.find(i)
        root_j = self.find(j)
        if root_i != root_j:
            if self.size[root_i] < self.size[root_j]:
                root_i, root_j = root_j, root_i
            self.parent[root_j] = root_i
            self.size[root_i] += self.size[root_j]
            return True
        return False

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    iterator = iter(input_data)
    num_test_cases = int(next(iterator))
    out = []
    
    for _ in range(num_test_cases):
        n = int(next(iterator))
        pi = [0] + [int(next(iterator)) for _ in range(n)]
        
        dsu = DSU(n)
        
        for i in range(1, n + 1):
            dsu.union(i, pi[i])
            
        cycles = []
        for i in range(1, n + 1):
            if dsu.parent[i] == i:
                cycles.append((dsu.size[i], i))
                
        num_cycles = len(cycles)
        
        if num_cycles == 1:
            k, i_ans, j_ans = n, 1, 1
        elif num_cycles == 2:
            k, i_ans, j_ans = n, cycles[0][1], cycles[1][1]
        else:
            cycles.sort(key=lambda x: x[0])
            l1, node1 = cycles[0]
            l2, node2 = cycles[1]
            l3, _ = cycles[2]
            k = min(l1 + l2, l3)
            i_ans, j_ans = node1, node2
            
        out.append(f"{k} {i_ans} {j_ans}")
        
    print("\n".join(out))

if __name__ == "__main__":
    solve()

import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    iterator = iter(input_data)
    t_str = next(iterator, None)
    if t_str is None:
        return
    num_test_cases = int(t_str)
    
    out = []
    
    for _ in range(num_test_cases):
        n = int(next(iterator))
        pi = [0] + [int(next(iterator)) for _ in range(n)]
        
        visited = [False] * (n + 1)
        cycles = []
        
        for start in range(1, n + 1):
            if not visited[start]:
                curr = start
                length = 0
                while not visited[curr]:
                    visited[curr] = True
                    curr = pi[curr]
                    length += 1
                cycles.append((length, start))
                
        num_cycles = len(cycles)
        
        if num_cycles == 1:
            k = n
            i = 1
            j = 1
        elif num_cycles == 2:
            k = n
            i = cycles[0][1]
            j = cycles[1][1]
        else:
            cycles.sort(key=lambda x: x[0])
            l1, node1 = cycles[0]
            l2, node2 = cycles[1]
            l3, _ = cycles[2]
            
            k = min(l1 + l2, l3)
            i = node1
            j = node2
            
        out.append(f"{k} {i} {j}")
        
    print("\n".join(out))

if __name__ == "__main__":
    solve()

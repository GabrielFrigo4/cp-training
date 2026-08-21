import sys
import math

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    n = int(input_data[0])
    q = int(input_data[1])
    
    a = [0] + [int(x) for x in input_data[2:n+2]]
    
    ptr = n + 2
    ans = [0] * q
    
    B = int(math.isqrt(n))
    
    m_queries = [[] for _ in range(B + 1)]
    
    for i in range(q):
        l = int(input_data[ptr])
        r = int(input_data[ptr+1])
        x = int(input_data[ptr+2])
        m = int(input_data[ptr+3])
        ptr += 4
        
        l_val = l + ((x - (l % m) + m) % m)
        r_val = r - (((r % m) - x + m) % m)
        
        if l_val > r_val:
            ans[i] = 0
            continue
        
        if m > B:
            total = 0
            curr = l_val
            while curr <= r_val:
                total += a[curr]
                curr += m
            ans[i] = total
        else:
            m_queries[m].append((i, l_val, r_val))
            
    pref = [0] * (n + 1)
    for m in range(1, B + 1):
        if not m_queries[m]:
            continue
        
        for i in range(1, n + 1):
            pref[i] = a[i] + (pref[i - m] if i >= m else 0)
            
        for q_idx, l_val, r_val in m_queries[m]:
            prev_idx = l_val - m
            res = pref[r_val] - (pref[prev_idx] if prev_idx >= 1 else 0)
            ans[q_idx] = res

    sys.stdout.write('\n'.join(str(x) for x in ans) + '\n')

if __name__ == "__main__":
    solve()


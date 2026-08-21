import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    n = int(input_data[0])
    q = int(input_data[1])
    
    a = [0] + [int(x) for x in input_data[2:n+2]]
    
    B = 80
    
    pref = [[0] * (n + 1) for _ in range(B + 1)]
    for m in range(1, B + 1):
        pm = pref[m]
        for i in range(1, n + 1):
            pm[i] = a[i] + (pm[i - m] if i >= m else 0)
            
    ptr = n + 2
    ans = [0] * q
    
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
        
        if m <= B:
            pm = pref[m]
            prev_idx = l_val - m
            ans[i] = pm[r_val] - (pm[prev_idx] if prev_idx >= 1 else 0)
        else:
            total = 0
            curr = l_val
            while curr <= r_val:
                total += a[curr]
                curr += m
            ans[i] = total

    sys.stdout.write('\n'.join(str(x) for x in ans) + '\n')

if __name__ == "__main__":
    solve()


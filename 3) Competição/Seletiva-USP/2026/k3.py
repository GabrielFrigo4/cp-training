import sys
from bisect import bisect_left

def precompute_distinct_numbers():
    nums = []
    
    def dfs(val, mask):
        nums.append(val)
        for nxt in range(10):
            if not (mask & (1 << nxt)):
                dfs(val * 10 + nxt, mask | (1 << nxt))
                
    for d in range(1, 10):
        dfs(d, 1 << d)
        
    nums.sort()
    return nums

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    distinct_numbers = precompute_distinct_numbers()
    total_nums = len(distinct_numbers)
    
    iterator = iter(input_data)
    num_test_cases = int(next(iterator))
    out = []
    
    for _ in range(num_test_cases):
        c = int(next(iterator))
        
        if c > 9876543210:
            out.append("-1")
            continue
            
        idx = bisect_left(distinct_numbers, c)
        if idx < total_nums:
            out.append(str(distinct_numbers[idx] - c))
        else:
            out.append("-1")
            
    sys.stdout.write("\n".join(out) + "\n")

if __name__ == "__main__":
    solve()

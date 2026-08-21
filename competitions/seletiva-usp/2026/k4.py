import sys
from bisect import bisect_left

def precompute_distinct_numbers():
    nums = []
    vals = list(range(1, 10))
    masks = [1 << d for d in range(1, 10)]
    
    for length in range(1, 11):
        nums.extend(vals)
        if length == 10:
            break
        next_vals = []
        next_masks = []
        for i in range(len(vals)):
            v = vals[i]
            m = masks[i]
            for nxt in range(10):
                if not (m & (1 << nxt)):
                    next_vals.append(v * 10 + nxt)
                    next_masks.append(m | (1 << nxt))
        vals = next_vals
        masks = next_masks
        
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

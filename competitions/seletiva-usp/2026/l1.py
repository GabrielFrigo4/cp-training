import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    n = int(input_data[0])
    a = input_data[1:n+1]
    
    counts = Counter(a)
    
    ans = 0
    for k in counts.values():
        ans += k * (k - 1) // 2
        
    print(ans)

if __name__ == "__main__":
    solve()

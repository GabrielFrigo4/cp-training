import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    n = int(input_data[0])
    a = [int(x) for x in input_data[1:n+1]]
    
    initial_evens = sum(1 for x in a if x % 2 == 0)
    
    b = [1 if x % 2 != 0 else -1 for x in a]
    
    max_gain = 0
    current_sum = 0
    
    for val in b:
        current_sum = max(val, current_sum + val)
        max_gain = max(max_gain, current_sum)
        
    ans = initial_evens + max_gain
    print(ans)

if __name__ == "__main__":
    solve()

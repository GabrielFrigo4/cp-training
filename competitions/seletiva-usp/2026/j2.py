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
    for l in range(n):
        current_sum = 0
        for r in range(l, n):
            current_sum += b[r]
            if current_sum > max_gain:
                max_gain = current_sum
                
    print(initial_evens + max_gain)

if __name__ == "__main__":
    solve()

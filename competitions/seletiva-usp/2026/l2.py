import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    n = int(input_data[0])
    a = [int(x) for x in input_data[1:n+1]]
    
    a.sort()
    
    ans = 0
    i = 0
    while i < n:
        j = i
        while j < n and a[j] == a[i]:
            j += 1
            
        k = j - i
        ans += k * (k - 1) // 2
        i = j
        
    print(ans)

if __name__ == "__main__":
    solve()

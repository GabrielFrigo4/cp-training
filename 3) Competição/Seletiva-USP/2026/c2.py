import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    s = input_data[0]
    n = len(s)
    res = []
    
    i = 0
    while i < n:
        j = i
        while j < n and s[j] == s[i]:
            j += 1
        
        count = j - i
        if count > 1:
            res.append(f"{s[i]}{count}")
        else:
            res.append(s[i])
            
        i = j
        
    print("".join(res))

if __name__ == "__main__":
    solve()

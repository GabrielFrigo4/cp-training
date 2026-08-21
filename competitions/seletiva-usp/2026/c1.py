import sys
from itertools import groupby

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    s = input_data[0]
    res = []
    
    for char, group in groupby(s):
        count = sum(1 for _ in group)
        if count > 1:
            res.append(f"{char}{count}")
        else:
            res.append(char)
            
    print("".join(res))

if __name__ == "__main__":
    solve()

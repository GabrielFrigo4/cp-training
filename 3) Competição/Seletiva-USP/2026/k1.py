import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    iterator = iter(input_data)
    num_test_cases = int(next(iterator))
    out = []
    
    for _ in range(num_test_cases):
        c = int(next(iterator))
        
        if c > 9876543210:
            out.append("-1")
            continue
            
        s = str(c)
        n = len(s)
        digits = [int(ch) for ch in s]
        
        if len(set(digits)) == n:
            out.append("0")
            continue
            
        found = False
        for p in range(n - 1, -1, -1):
            pref = digits[:p]
            if len(set(pref)) != p:
                continue
                
            mask = 0
            for d in pref:
                mask |= (1 << d)
                
            found_digit = -1
            for d in range(digits[p] + 1, 10):
                if not (mask & (1 << d)):
                    found_digit = d
                    break
                    
            if found_digit != -1:
                res = pref + [found_digit]
                mask |= (1 << found_digit)
                
                for _ in range(p + 1, n):
                    for cand in range(10):
                        if not (mask & (1 << cand)):
                            res.append(cand)
                            mask |= (1 << cand)
                            break
                            
                val = int("".join(map(str, res)))
                out.append(str(val - c))
                found = True
                break
                
        if not found:
            if n < 10:
                first = [1, 0, 2, 3, 4, 5, 6, 7, 8, 9]
                val = int("".join(map(str, first[:n + 1])))
                out.append(str(val - c))
            else:
                out.append("-1")
                
    sys.stdout.write("\n".join(out) + "\n")

if __name__ == "__main__":
    solve()

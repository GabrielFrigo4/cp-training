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
        
        def search(pos, is_greater, mask):
            if pos == n:
                return []
                
            curr_d = digits[pos] if not is_greater else 0
            for d in range(curr_d, 10):
                if pos == 0 and d == 0:
                    continue
                if not (mask & (1 << d)):
                    new_greater = is_greater or (d > digits[pos])
                    if new_greater:
                        res = [d]
                        cur_mask = mask | (1 << d)
                        for _ in range(pos + 1, n):
                            for cand in range(10):
                                if not (cur_mask & (1 << cand)):
                                    res.append(cand)
                                    cur_mask |= (1 << cand)
                                    break
                        return res
                    else:
                        sub = search(pos + 1, False, mask | (1 << d))
                        if sub is not None:
                            return [d] + sub
            return None

        res = search(0, False, 0)
        if res is not None:
            val = int("".join(map(str, res)))
            out.append(str(val - c))
        else:
            if n < 10:
                first = [1, 0, 2, 3, 4, 5, 6, 7, 8, 9]
                val = int("".join(map(str, first[:n + 1])))
                out.append(str(val - c))
            else:
                out.append("-1")
                
    sys.stdout.write("\n".join(out) + "\n")

if __name__ == "__main__":
    solve()

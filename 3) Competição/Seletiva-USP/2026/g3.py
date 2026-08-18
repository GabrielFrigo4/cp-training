import sys
import math
from fractions import Fraction

def generate_expressions():
    exprs = {1: {}, 2: {}, 3: {}, 4: {}}

    def add(k, val, s, prec):
        if len(s) > 25:
            return
        if s.count("4") != k:
            return
        if val not in exprs[k] or len(s) < len(exprs[k][val][0]):
            exprs[k][val] = (s, prec)

    add(1, Fraction(4, 1), "4", 4)
    add(1, Fraction(4, 10), ".4", 4)

    def apply_unary(k):
        items = list(exprs[k].items())
        for val, (s, prec) in items:
            if val >= 0 and val.denominator == 1:
                n = val.numerator
                r = int(math.isqrt(n))
                if r * r == n:
                    add(k, Fraction(r, 1), f"sqrt({s})", 4)
            if val >= 0 and val.denominator == 1 and val.numerator <= 8:
                n = val.numerator
                fact = math.factorial(n)
                s_fact = s if prec == 4 else f"({s})"
                add(k, Fraction(fact, 1), f"{s_fact}!", 4)

    apply_unary(1)
    apply_unary(1)

    add(2, Fraction(44, 1), "44", 4)
    add(2, Fraction(44, 10), "4.4", 4)
    add(2, Fraction(44, 100), ".44", 4)
    apply_unary(2)

    def wrap(s, p_sub, p_op, is_right=False, non_assoc=False):
        if p_sub < p_op or (is_right and non_assoc and p_sub == p_op):
            return f"({s})"
        return s

    def combine(k1, k2):
        k = k1 + k2
        for v1, (s1, p1) in exprs[k1].items():
            for v2, (s2, p2) in exprs[k2].items():
                add(k, v1 + v2, f"{wrap(s1, p1, 1)}+{wrap(s2, p2, 1)}", 1)
                add(k, v1 - v2, f"{wrap(s1, p1, 1)}-{wrap(s2, p2, 1, is_right=True, non_assoc=True)}", 1)
                add(k, v1 * v2, f"{wrap(s1, p1, 2)}*{wrap(s2, p2, 2)}", 2)
                if v2 != 0:
                    add(k, v1 / v2, f"{wrap(s1, p1, 2)}/{wrap(s2, p2, 2, is_right=True, non_assoc=True)}", 2)
                if v2.denominator == 1 and 0 <= v2.numerator <= 6:
                    try:
                        p = v1 ** v2.numerator
                        if p.numerator < 10**9 and p.denominator < 10**9:
                            add(k, p, f"{wrap(s1, p1, 3)}^{wrap(s2, p2, 3, is_right=True)}", 3)
                    except:
                        pass

    combine(1, 1)
    apply_unary(2)
    apply_unary(2)

    combine(1, 2)
    combine(2, 1)
    apply_unary(3)
    apply_unary(3)

    combine(1, 3)
    combine(3, 1)
    combine(2, 2)
    apply_unary(4)
    apply_unary(4)

    solutions = {}
    for x in range(71):
        frac = Fraction(x, 1)
        solutions[x] = exprs[4][frac][0]
        
    return solutions

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    solutions = generate_expressions()
    
    iterator = iter(input_data)
    num_test_cases = int(next(iterator))
    out = []
    
    for _ in range(num_test_cases):
        x = int(next(iterator))
        out.append(solutions[x])
        
    sys.stdout.write("\n".join(out) + "\n")

if __name__ == "__main__":
    solve()

import sys
from functools import cache
sys.setrecursionlimit(10**6)

N = int(input())
A = [int(a) for a in input().split()]
pos = {valor: i for i, valor in enumerate(A)}

@cache
def dp(i):
	if i >= 2*N - 1:
		return (0, 0)
	cur = dp(i+1)
	if pos[A[i]] > i:
		new = (dp(pos[A[i]])[0] + 1, dp(pos[A[i]])[1] - pos[A[i]] + i)
		return max(cur, new)
	return cur

print(f"{dp(0)[0]} {-dp(0)[1]}")


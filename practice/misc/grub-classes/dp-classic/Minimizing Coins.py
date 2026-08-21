import sys
sys.setrecursionlimit(2**28)

n, x = [int(i) for i in input().split()]
c = [int(i) for i in input().split()]
c.sort()

memo = [-2**60] * (x + 1)
memo[0] = 0

def dp(v):
	global memo
	global n, x, c

	if (v < 0):
		return -1
	if memo[v] >= -1:
		return memo[v]
	memo[v] = -1
	for _c in c:
		if (_c > v):
			break
		if (dp(v - _c) > -1):
			if (memo[v] == -1):
				memo[v] = memo[v - _c] + 1
			else:
				memo[v] = min(memo[v], memo[v - _c] + 1)
	return memo[v]

for i in range(x):
	dp(i)

print(dp(x))

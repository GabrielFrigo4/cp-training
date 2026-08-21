import sys
sys.setrecursionlimit(2**28)

n, x = [int(i) for i in input().split()]
c = [int(i) for i in input().split()]
c.sort()

memo = [-1] * (x + 1)
memo[0] = 0

def dp(v):
	global memo
	global n, x, c

	if (v < 0):
		return 0
	if (memo[v] > -1):
		return memo[v]
	memo[v] = 0
	for _c in c:
		if (_c > v):
			break
		if (_c == v):
			memo[v] += 1
		if (dp(v - _c) > -1):
			memo[v] += memo[v - _c]
			memo[v] %= 10**9 + 7
	return memo[v]

for i in range(x):
	dp(i)

print(dp(x))

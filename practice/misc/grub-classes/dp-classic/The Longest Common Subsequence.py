import sys
sys.setrecursionlimit(2**28)

NULL = -1
D = 0
V = 1
H = 2

def dp(memo, sol, n, m, a, b):
	if (n == -1 or m == -1):
		return 0
	if (memo[n][m] > -1):
		return memo[n][m]
	if (a[n] == b[m]):
		memo[n][m] = dp(memo, sol, n - 1, m - 1, a, b) + 1
		sol[n][m] = D
	else:
		v = dp(memo, sol, n - 1, m, a, b)
		h = dp(memo, sol, n, m - 1, a, b)
		if (h >= v):
			memo[n][m] = h
			sol[n][m] = H
		else:
			memo[n][m] = v
			sol[n][m] = V
	return memo[n][m]

def rec(sol, res, n, m, a, b):
	if (n == -1 or m == -1):
		return res
	elif (sol[n][m] == D):
		res.append(a[n])
		res = rec(sol, res, n - 1, m - 1, a, b)
	elif (sol[n][m]) == V:
		res = rec(sol, res, n - 1, m, a, b)
	else:
		res = rec(sol, res, n, m - 1, a, b)
	return res

def longestCommonSubsequence(a, b):
	n = len(a)
	m = len(b)
	memo = [[-1] * m for _ in range(n)]
	sol = [[NULL] * m for _ in range(n)]
	res = []
	dp(memo, sol, n - 1, m - 1, a, b)
	res = rec(sol, res, n - 1, m - 1, a, b)
	return res[::-1]
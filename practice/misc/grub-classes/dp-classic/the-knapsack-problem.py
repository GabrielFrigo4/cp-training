import sys
sys.setrecursionlimit(2**28)

S, N = [int(i) for i in input().split()]
I = []
for i in range(N):
	I.append([int(j) for j in input().split()])

memo = [[0] * (N + 1) for i in range(S + 1)]

for s in range(1, S + 1):
	for n in range(1, N + 1):
		if (s < I[n - 1][0]):
			memo[s][n] = memo[s][n - 1]
		else:
			curr = memo[s - I[n - 1][0]][n - 1] + I[n - 1][1]
			memo[s][n] = max(memo[s][n - 1], curr)

print(memo[S][N])

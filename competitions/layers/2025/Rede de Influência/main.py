N, M = [int(_) for _ in input().split()]
mat = [[False] * N for _ in range(N)]
color = [-1] * N
for i in range(M):
	A, B = [int(_) for _ in input().split()]
	A -= 1
	B -= 1
	mat[A][B] = True

def dfs(s, e, c, lst):
	global N, mat, color

	if (s == e and len(lst) > 0):
		return c
	if (e in lst or color[e] > 0):
		return 0
	lst.append(e);

	clr = 0
	for i in range(N):
		if (mat[e][i]):
			clr = max(clr, dfs(s, i, c, lst[:]))
	color[e] = clr
	return clr

def main():
	global N, mat, color
	c = 0
	for i in range(N):
		if (color[i] == -1):
			c += 1
			dfs(i, i, c, [])
			color[i] = c
	print(c)

main()
import numpy as np
import itertools

def op_vec(mat, vec):
	out = mat @ vec
	for i in range(len(out)):
		out[i] %= 2
	return out

def op_mat(mat1, mat2):
	out = mat1 @ mat2
	for y in range(len(out)):
		for x in range(len(out[y])):
			out[y][x] %= 2
	return out

def exp_mat(mat, exp):
	if exp == 1:
		return mat
	out = exp_mat(mat, exp//2)
	out = op_mat(out, out)
	if exp % 2 == 1:
		out = op_mat(out, mat)
	return out	

def display(out):
	global N, buf_s
	for i in range(len(out)):
		if (buf_s[i] == "#"):
			print("#", end="")
		else:
			print(out[i], end="")
		if i % N + 1 == N:
			print()

N, K = [int(_) for _ in input().split()]
S = [input() for _ in range(N)]

buf_s = ""
for s in S:
	buf_s += s

buf_b = []
for c in buf_s:
	buf_b.append(int(c == "1"))

buf_m = [[0] * (N ** 2) for _ in range(N ** 2)]
for i in range(N ** 2):
	if buf_s[i] == "#":
		continue
	tmp = [[0] * N for _ in range(N)]
	pos = (i // N, i % N)
	edges = list(itertools.product([-1, 0, 1], repeat=2))
	for edge in edges:
		p = list(map(sum, zip(pos, edge)))
		p[0] = int(np.clip(p[0], 0, N-1))
		p[1] = int(np.clip(p[1], 0, N-1))
		tmp[p[0]][p[1]] = 1
	buf_m[i] = []
	for t in tmp:
		buf_m[i] += t

vec = np.array(buf_b)
mat = np.array(buf_m)
mat = exp_mat(mat, K)
out = op_vec(mat, vec)
display(out)


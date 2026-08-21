import sys
sys.setrecursionlimit(2**28)

l = int(input())
n = int(input())
p = []
for i in range(n):
	length, value = [int(j) for j in input().split()]
	p.append((length, value))
p.sort()

r = [-2**60] * (l + 1)
r[0] = 0
for i in range(1, l + 1):
	r[i] = r[i - 1]
	for length, value in p:
		if (length > i):
			break
		r[i] = max(r[i], value + r[i - length])

print(r[l])

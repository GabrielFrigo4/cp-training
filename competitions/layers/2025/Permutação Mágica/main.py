N = int(input())
d = [0] * max(N+1, 3)
d[0] = 1
d[1] = 0
d[2] = 1

for i in range(3, N + 1):
	d[i] = (i - 1) * (d[i-1] + d[i-2])
print(d[N])

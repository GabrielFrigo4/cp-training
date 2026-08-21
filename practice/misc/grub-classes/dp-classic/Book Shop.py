from array import array

n, x = map(int, input().split())
h = array('i', list(map(int, input().split())))
s = array('i', list(map(int, input().split())))

dp = array('i', [0] * (x + 1))

for i in range(n):
	price, pages = h[i], s[i]
	for j in range(x, price - 1, -1):
		new_val = dp[j - price] + pages
		if new_val > dp[j]:
			dp[j] = new_val

print(dp[x])

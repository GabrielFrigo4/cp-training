from array import array

n = array('B', (ord(c) for c in input()))
m = array('B', (ord(c) for c in input()))

prev = array('H', range(len(m) + 1))
curr = array('H', [0] * (len(m) + 1))

for i in range(1, len(n) + 1):
	curr[0] = i
	for j in range(1, len(m) + 1):
		cost = 0 if n[i-1] == m[j-1] else 1
		curr[j] = min(
			prev[j] + 1,
			curr[j-1] + 1,
			prev[j-1] + cost
		)
	prev, curr = curr, prev

print(prev[len(m)])

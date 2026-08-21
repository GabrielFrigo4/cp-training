k = int(input())
s = list(input())

for i in range(len(s)):
	c = ord(s[i])
	c -= ord('a')
	c -= i * k
	c %= ord('z') - ord('a') + 1
	c += ord('a')
	s[i] = chr(c)

print("".join(s))

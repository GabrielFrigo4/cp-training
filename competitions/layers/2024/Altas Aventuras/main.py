import math

l = input().split()
n = int(l[0])
k = int(l[1])
output = 0

while (k > 2 and n > 0):
	k -= 1
	output += 1
	n = n // 2

if k == 2:
	a = 1
	b = 1
	c = -2*n
	x = (-b + math.sqrt(b**2 - 4*a*c)) / (2*a)
	x = math.ceil(x)
	output += x
elif k == 1:
	output += n

print(output)

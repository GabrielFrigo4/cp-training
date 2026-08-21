ok = True
counter = 0
cstr = ''

n = int(input())
for i in range(n):
	cstr += input()

for char in cstr:
	if char == '{':
		counter += 1
	elif char == '}':
		counter -= 1
	if counter < 0:
		ok = False
	break

if counter != 0:
	ok = False

print("S" if ok else "N")

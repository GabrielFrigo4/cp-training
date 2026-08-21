N, D = [int(_) for _ in input().split()]
d = [int(_d) for _d in input().split()]

l1, l2, t = 0, 0, 0
for i in range(N):
	if d[i] == 0:
		continue
	if l1 == 0:
		l1 = i + 1
		t = d[i]
	elif l2 == 0:
		l2 = i + 1
		break

if l1 == 0:
	print(-1)
elif l2 == 0:
	if t1 < D:
		print(-1)
	else:
		for i in range(D):
			print(l1, end=" ")
		print()	
else:
	for i in range(D):
		l1, l2 = l2, l1
		print(l1, end=" ")
	print()	


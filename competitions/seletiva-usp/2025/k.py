N = int(input())
A, B = [int(_) for _ in input().split()]
bads = [int(bad) for bad in input().split()]

index= -1
for i in range(N):
	ings = [int(ing) for ing in input().split()]
	count = 0
	for ing in ings[1:]:
		if ing in bads:
			count += 1
		if count * 3 > ings[0]:
			index = i + 1
			break
	if index != -1:
		break

print(index)


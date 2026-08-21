N = int(input())
D = input()

sufix = [0] * (N + 1)
for i in range(N, 0, -1):
	sufix[i - 1] = sufix[i] + int(D[i - 1] == ")")

pairs = 0
opens = 0
region = 0
for i in range(N):
	opens += int(D[i] == "(")
	region += int(D[i] == "(") - int(D[i] == ")")
	if region == 0:
		pairs += opens * sufix[i + 1]
		opens = 0

print(pairs)


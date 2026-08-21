class Solution:
	def dp(self, arr, l, r):
		if (l == r):
			return 0
		if (self.memo[l][r] > 0):
			return self.memo[l][r]
		self.memo[l][r] = 2 ** 60
		for i in range(l, r):
			curr = self.dp(arr, l, i) + self.dp(arr, i + 1, r) + arr[l - 1] * arr[i] * arr[r]
			self.memo[l][r] = min(self.memo[l][r], curr)
		return self.memo[l][r]

	def matrixMultiplication(self, arr):
		self.memo = [[0] * len(arr) for _ in range(len(arr))]
		return self.dp(arr, 1, len(arr) - 1)

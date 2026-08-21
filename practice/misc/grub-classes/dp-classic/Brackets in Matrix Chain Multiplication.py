class Solution:
	def rec(self, l, r):
		if (l == r):
			self.res += f"{chr(ord("A") + l - 1)}"
			return self.res
		self.res += "("
		self.rec(l, self.sol[l][r])
		self.rec(self.sol[l][r] + 1, r)
		self.res += ")"
		return self.res

	def dp(self, arr, l, r):
		if (l == r):
			return 0
		if (self.memo[l][r] > 0):
			return self.memo[l][r]
		self.memo[l][r] = 2 ** 60
		for i in range(l, r):
			curr = self.dp(arr, l, i) + self.dp(arr, i + 1, r) + arr[l - 1] * arr[i] * arr[r]
			if (curr < self.memo[l][r]):
				self.memo[l][r] = curr
				self.sol[l][r] = i
		return self.memo[l][r]

	def matrixChainOrder(self, arr):
		self.memo = [[0] * len(arr) for _ in range(len(arr))]
		self.sol = [[0] * len(arr) for _ in range(len(arr))]
		self.res = ''
		self.dp(arr, 1, len(arr) - 1)
		return self.rec(1, len(arr) - 1)
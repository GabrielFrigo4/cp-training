class Solution:
	def dp(self, price, m):
		if (self.r[m] >= 0):
			return self.r[m]
		self.r[m] = self.r[m - 1]
		for i in range(m):
			self.r[m] = max(self.r[m], price[i] + self.dp(price, m - i - 1))
		return self.r[m]

	def cutRod(self, price):
		n = len(price)
		self.r = [-2**60] * (n + 1)
		self.r[0] = 0
		return self.dp(price, n)

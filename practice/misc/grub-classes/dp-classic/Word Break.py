class Solution:
	def dp(self, i):
		if (self.memo[i] > -1):
			return self.memo[i]
		self.memo[i] = 0
		for _d in self.d:
			if (i < len(_d)):
				continue
			if (self.dp(i - len(_d)) == 1 and self.s[(i - len(_d)):i] == _d):
				self.memo[i] = 1
				break
		return self.memo[i]

	def wordBreak(self, s, dictionary):
		self.s = s
		self.d = dictionary
		self.memo = [-1] * (len(s) + 1)
		self.memo[0] = 1
		return bool(self.dp(len(s)))

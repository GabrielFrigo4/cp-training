class Solution:
	def dp(self, s: str, l: int, r: int) -> int:
		if (l >= r):
			return int(l == r)
		if (self.memo[l][r] > -1):
			return self.memo[l][r]
		if (s[l] == s[r]):
			self.memo[l][r] = self.dp(s, l + 1, r - 1) + 2
		else:
			self.memo[l][r] = max(self.dp(s, l +1, r), self.dp(s, l, r - 1))
		return self.memo[l][r]

	def longestPalindromeSubseq(self, s: str) -> int:
		self.memo = [[-1] * len(s) for _ in range(len(s))]
		return self.dp(s, 0, len(s) - 1)
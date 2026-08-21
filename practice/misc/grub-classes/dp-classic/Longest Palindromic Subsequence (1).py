class Solution:
	def dp(self, text1: str, text2: str, i1: int, i2: int) -> int:
		if (i1 == -1 or i2 == -1):
			return 0
		if (self.memo[i1][i2] > -1):
			return self.memo[i1][i2]
		if (text1[i1] == text2[i2]):
			self.memo[i1][i2] = self.dp(text1, text2, i1 - 1, i2 - 1) + 1
		else:
			self.memo[i1][i2] = max(self.dp(text1, text2, i1 - 1, i2), self.dp(text1, text2, i1, i2 - 1))
		return self.memo[i1][i2]

	def longestCommonSubsequence(self, text1: str, text2: str) -> int:
		self.memo = [[-1] * len(text2) for _ in range(len(text1))]
		return self.dp(text1, text2, len(text1) - 1, len(text2) - 1)

	def longestPalindromeSubseq(self, s: str) -> int:
		return self.longestCommonSubsequence(s, s[::-1])
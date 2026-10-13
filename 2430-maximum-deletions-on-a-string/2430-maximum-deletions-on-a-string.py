class Solution:
    def deleteString(self, s: str) -> int:
        n = len(s)
        dp = [1] * n
        lcp = [0] * (n + 1)

        for i in range(n - 2, -1, -1):
            limit = i + (n - i) // 2

            for j in range(i + 1, n):
                if s[i] == s[j]:
                    lcp[j] = lcp[j + 1] + 1
                else:
                    lcp[j] = 0

                if j <= limit and lcp[j] >= j - i:
                    dp[i] = max(dp[i], dp[j] + 1)
        
        return dp[0]
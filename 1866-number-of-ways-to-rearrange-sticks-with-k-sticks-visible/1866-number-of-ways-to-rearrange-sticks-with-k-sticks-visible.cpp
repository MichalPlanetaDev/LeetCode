class Solution {
public:
    int rearrangeSticks(int n, int k) {
        const int mod = 1e9 + 7;
        vector<int> dp(k + 1);
        dp[0] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = min(i, k); j >= 1; --j) {
                dp[j] = (dp[j - 1] + 1LL * (i - 1) * dp[j]) % mod;
            }
            dp[0] = 0;
        }

        return dp[k];
    }
};
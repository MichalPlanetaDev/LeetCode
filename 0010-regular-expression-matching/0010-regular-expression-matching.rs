impl Solution {
    pub fn is_match(s: String, p: String) -> bool {
        let s = s.as_bytes();
        let p = p.as_bytes();
        let n = s.len();
        let mut dp = vec![false; n + 1];
        dp[0] = true;

        let mut i = 0;
        while i < p.len() {
            let c = p[i];

            if i + 1 < p.len() && p[i + 1] == b'*' {
                for j in 1..=n {
                    dp[j] |= dp[j - 1] && (c == b'.' || c == s[j - 1]);
                }
                i += 2;
            } else {
                for j in (1..=n).rev() {
                    dp[j] = dp[j - 1] && (c == b'.' || c == s[j - 1]);
                }
                dp[0] = false;
                i += 1;
            }
        }
        dp[n]
    }
}
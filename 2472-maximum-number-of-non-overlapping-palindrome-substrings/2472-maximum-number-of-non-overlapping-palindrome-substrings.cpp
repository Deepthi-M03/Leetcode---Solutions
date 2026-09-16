class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // palindrome[i][j] is true if s[i...j] is a palindrome
        vector<vector<bool>> palindrome(
            n, vector<bool>(n, false)
        );

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] &&
                    (j - i <= 2 || palindrome[i + 1][j - 1])) {
                    palindrome[i][j] = true;
                }
            }
        }

        // dp[i] = maximum palindromes in the first i characters
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            // Do not select a palindrome ending at i - 1
            dp[i] = dp[i - 1];

            // Check a palindrome of length k
            if (i >= k && palindrome[i - k][i - 1]) {
                dp[i] = max(dp[i], dp[i - k] + 1);
            }

            // Checking length k + 1 is also sufficient
            if (i >= k + 1 && palindrome[i - k - 1][i - 1]) {
                dp[i] = max(dp[i], dp[i - k - 1] + 1);
            }
        }

        return dp[n];
    }
};
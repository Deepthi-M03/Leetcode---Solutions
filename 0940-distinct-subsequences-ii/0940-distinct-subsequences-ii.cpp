class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        long long total = 1; // includes empty subsequence
        vector<long long> last(26, 0);

        for (char c : s) {
            int idx = c - 'a';

            long long newTotal = (2 * total - last[idx] + MOD) % MOD;

            last[idx] = total;
            total = newTotal;
        }

        // Remove empty subsequence
        return (total - 1 + MOD) % MOD;
    }
};
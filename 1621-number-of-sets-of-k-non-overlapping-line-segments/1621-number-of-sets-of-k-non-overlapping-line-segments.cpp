class Solution {
public:
    static const int MOD = 1000000007;

    long long power(long long base, long long exponent) {
        long long result = 1;

        while (exponent > 0) {
            if (exponent & 1) {
                result = result * base % MOD;
            }

            base = base * base % MOD;
            exponent >>= 1;
        }

        return result;
    }

    int numberOfSets(int n, int k) {
        int total = n + k - 1;
        int selected = 2 * k;

        vector<long long> factorial(total + 1, 1);

        for (int i = 1; i <= total; i++) {
            factorial[i] = factorial[i - 1] * i % MOD;
        }

        long long denominator =
            factorial[selected] * factorial[total - selected] % MOD;

        long long answer =
            factorial[total] * power(denominator, MOD - 2) % MOD;

        return static_cast<int>(answer);
    }
};
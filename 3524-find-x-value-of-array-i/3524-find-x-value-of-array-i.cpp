class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            int val = num % k;
            vector<long long> newDp(k, 0);

            // Start a new subarray with current element
            newDp[val]++;

            // Extend all previous subarrays
            for (int r = 0; r < k; r++) {
                int newRemainder = (r * val) % k;
                newDp[newRemainder] += dp[r];
            }

            // Add all subarrays ending here to result
            for (int r = 0; r < k; r++) {
                result[r] += newDp[r];
            }

            dp = newDp;
        }

        return result;
    }
};
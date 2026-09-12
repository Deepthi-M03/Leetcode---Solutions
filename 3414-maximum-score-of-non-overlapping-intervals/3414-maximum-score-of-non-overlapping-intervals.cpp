class Solution {
    struct State {
        long long score = 0;
        vector<int> indices;
    };

    bool better(const State& a, const State& b) {
        if (a.score != b.score) {
            return a.score > b.score;
        }

        return a.indices < b.indices;
    }

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // {right, left, weight, original index}
        vector<array<long long, 4>> data;

        for (int i = 0; i < n; i++) {
            data.push_back({
                intervals[i][1],
                intervals[i][0],
                intervals[i][2],
                i
            });
        }

        sort(data.begin(), data.end());

        vector<long long> rightEnds(n);

        for (int i = 0; i < n; i++) {
            rightEnds[i] = data[i][0];
        }

        // dp[i][k] = best answer using first i intervals
        // while selecting at most k intervals
        vector<vector<State>> dp(n + 1, vector<State>(5));

        for (int i = 1; i <= n; i++) {
            long long right = data[i - 1][0];
            long long left = data[i - 1][1];
            long long weight = data[i - 1][2];
            int originalIndex = static_cast<int>(data[i - 1][3]);

            // Number of earlier intervals whose right endpoint is < left
            int previous = lower_bound(
                rightEnds.begin(),
                rightEnds.begin() + i - 1,
                left
            ) - rightEnds.begin();

            for (int k = 1; k <= 4; k++) {
                // Option 1: Do not select the current interval
                dp[i][k] = dp[i - 1][k];

                // Option 2: Select the current interval
                State take = dp[previous][k - 1];
                take.score += weight;
                take.indices.push_back(originalIndex);

                // Required answer indices must be sorted
                sort(take.indices.begin(), take.indices.end());

                if (better(take, dp[i][k])) {
                    dp[i][k] = take;
                }
            }
        }

        return dp[n][4].indices;
    }
};
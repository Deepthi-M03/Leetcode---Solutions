class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        // best[i] = minimum length of a valid subarray
        // completely contained within arr[0...i]
        vector<int> best(n, INF);

        int left = 0;
        int currentSum = 0;
        int minimumLength = INF;
        int answer = INF;

        for (int right = 0; right < n; right++) {
            currentSum += arr[right];

            while (currentSum > target && left <= right) {
                currentSum -= arr[left];
                left++;
            }

            if (currentSum == target) {
                int currentLength = right - left + 1;

                // Combine with a valid non-overlapping subarray
                if (left > 0 && best[left - 1] != INF) {
                    answer = min(
                        answer,
                        currentLength + best[left - 1]
                    );
                }

                minimumLength = min(minimumLength, currentLength);
            }

            best[right] = minimumLength;
        }

        return answer == INF ? -1 : answer;
    }
};
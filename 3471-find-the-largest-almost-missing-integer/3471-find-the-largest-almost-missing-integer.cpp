class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int count[51] = {0};

        for (int i = 0; i <= nums.size() - k; i++) {
            bool seen[51] = {false};

            for (int j = i; j < i + k; j++) {
                if (!seen[nums[j]]) {
                    count[nums[j]]++;
                    seen[nums[j]] = true;
                }
            }
        }

        int ans = -1;

        for (int x = 50; x >= 0; x--) {
            if (count[x] == 1) {
                return x;
            }
        }

        return -1;
    }
};
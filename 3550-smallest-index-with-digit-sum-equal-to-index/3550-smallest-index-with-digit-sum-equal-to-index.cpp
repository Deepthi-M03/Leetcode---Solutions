class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        auto digitSum = [](int x) {
            int sum = 0;
            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }
            return sum;
        };
        
        for (int i = 0; i < nums.size(); i++) {
            if (digitSum(nums[i]) == i) {
                return i;
            }
        }
        return -1;
    }
};

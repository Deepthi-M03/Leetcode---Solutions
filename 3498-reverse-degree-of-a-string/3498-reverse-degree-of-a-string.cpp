class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;

        for (int i = 0; i < s.length(); i++) {
            int reverseValue = 26 - (s[i] - 'a');
            sum += reverseValue * (i + 1);
        }

        return sum;
    }
};
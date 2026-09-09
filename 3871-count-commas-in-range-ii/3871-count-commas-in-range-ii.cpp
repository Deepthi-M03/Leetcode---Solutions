class Solution {
public:
    long long countCommas(long long n) {
        long long answer = 0;

        for (long long place = 1000; place <= n; ) {
            answer += n - place + 1;

            // Prevent overflow
            if (place > n / 1000) {
                break;
            }

            place *= 1000;
        }

        return answer;
    }
};
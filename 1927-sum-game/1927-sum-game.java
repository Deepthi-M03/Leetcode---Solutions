class Solution {
    public boolean sumGame(String num) {
        int n = num.length();
        int diff = 0;
        int q = 0;

        for (int i = 0; i < n; i++) {
            if (num.charAt(i) == '?') {
                q += (i < n / 2) ? 1 : -1;
            } else {
                int digit = num.charAt(i) - '0';
                diff += (i < n / 2) ? digit : -digit;
            }
        }

        return 2 * diff != -9 * q;
    }
}
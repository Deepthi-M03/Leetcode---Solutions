class Solution {
    public String shortestBeautifulSubstring(String s, int k) {
        String ans = "";

        for (int i = 0; i < s.length(); i++) {
            int ones = 0;

            for (int j = i; j < s.length(); j++) {
                if (s.charAt(j) == '1') {
                    ones++;
                }

                if (ones == k) {
                    String sub = s.substring(i, j + 1);

                    if (ans.isEmpty() ||
                        sub.length() < ans.length() ||
                        (sub.length() == ans.length() && sub.compareTo(ans) < 0)) {
                        ans = sub;
                    }

                    break;
                }
            }
        }

        return ans;
    }
}
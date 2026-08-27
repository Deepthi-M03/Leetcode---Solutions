class Solution {
    public String lexGreaterPermutation(String s, String target) {
        int[] cnt = new int[26];

        for (char c : s.toCharArray())
            cnt[c - 'a']++;

        StringBuilder ans = new StringBuilder();

        // Match target as much as possible
        for (int i = 0; i < target.length(); i++) {
            int cur = target.charAt(i) - 'a';

            if (cnt[cur] > 0) {
                ans.append(target.charAt(i));
                cnt[cur]--;
            } else {
                // Try smallest character greater than target[i]
                for (int c = cur + 1; c < 26; c++) {
                    if (cnt[c] > 0) {
                        ans.append((char) ('a' + c));
                        cnt[c]--;
                        fill(ans, cnt);
                        return ans.toString();
                    }
                }

                // Backtrack
                while (ans.length() > 0) {
                    char removed = ans.charAt(ans.length() - 1);
                    ans.deleteCharAt(ans.length() - 1);
                    cnt[removed - 'a']++;

                    int pos = ans.length();
                    int need = target.charAt(pos) - 'a';

                    for (int c = need + 1; c < 26; c++) {
                        if (cnt[c] > 0) {
                            ans.append((char) ('a' + c));
                            cnt[c]--;
                            fill(ans, cnt);
                            return ans.toString();
                        }
                    }
                }

                return "";
            }
        }

        // Exact target was formed, so find the next greater permutation
        while (ans.length() > 0) {
            char removed = ans.charAt(ans.length() - 1);
            ans.deleteCharAt(ans.length() - 1);
            cnt[removed - 'a']++;

            int pos = ans.length();
            int need = target.charAt(pos) - 'a';

            for (int c = need + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    ans.append((char) ('a' + c));
                    cnt[c]--;
                    fill(ans, cnt);
                    return ans.toString();
                }
            }
        }

        return "";
    }

    private void fill(StringBuilder ans, int[] cnt) {
        for (int c = 0; c < 26; c++) {
            while (cnt[c] > 0) {
                ans.append((char) ('a' + c));
                cnt[c]--;
            }
        }
    }
}
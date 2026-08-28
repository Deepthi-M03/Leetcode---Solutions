class Solution {
    public String lexPalindromicPermutation(String s, String target) {
        int n = s.length();
        int[] cnt = new int[26];

        for (char ch : s.toCharArray())
            cnt[ch - 'a']++;

        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) {
                odd++;
                mid = (char) ('a' + i);
            }
        }

        // Palindrome impossible
        if (odd > 1 || (n % 2 == 0 && odd != 0))
            return "";

        int[] half = new int[26];

        for (int i = 0; i < 26; i++)
            half[i] = cnt[i] / 2;

        int m = n / 2;
        StringBuilder left = new StringBuilder();

        for (int pos = 0; pos < m; pos++) {
            boolean found = false;

            for (int c = 0; c < 26; c++) {
                if (half[c] == 0)
                    continue;

                half[c]--;
                left.append((char) ('a' + c));

                String max = buildMax(left, half, mid, n);

                if (max.compareTo(target) > 0) {
                    found = true;
                    break;
                }

                left.deleteCharAt(left.length() - 1);
                half[c]++;
            }

            if (!found)
                return "";
        }

        StringBuilder ans = new StringBuilder(left);

        if (n % 2 == 1)
            ans.append(mid);

        ans.append(new StringBuilder(left).reverse());

        String result = ans.toString();

        return result.compareTo(target) > 0 ? result : "";
    }

    private String buildMax(StringBuilder prefix, int[] half,
                            char mid, int n) {

        StringBuilder left = new StringBuilder(prefix);

        for (int c = 25; c >= 0; c--) {
            for (int j = 0; j < half[c]; j++)
                left.append((char) ('a' + c));
        }

        StringBuilder res = new StringBuilder(left);

        if (n % 2 == 1)
            res.append(mid);

        res.append(new StringBuilder(left).reverse());

        return res.toString();
    }
}
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        // Store key-value pairs
        for (auto &k : knowledge) {
            mp[k[0]] = k[1];
        }

        string ans;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {
                // Find the closing bracket
                int j = i + 1;
                string key = "";

                while (s[j] != ')') {
                    key += s[j];
                    j++;
                }

                // Check if key exists
                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                } else {
                    ans += "?";
                }

                // Skip everything up to ')'
                i = j;
            }
            else {
                ans += s[i];
            }
        }

        return ans;
    }
};
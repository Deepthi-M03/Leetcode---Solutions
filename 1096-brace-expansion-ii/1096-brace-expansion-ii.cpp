class Solution {
public:
    string s;
    int pos;

    set<string> parseExpression() {
        set<string> result = parseTerm();

        while (pos < s.size() && s[pos] == ',') {
            pos++;
            set<string> next = parseTerm();

            result.insert(next.begin(), next.end());
        }

        return result;
    }

    set<string> parseTerm() {
        set<string> result;
        result.insert("");

        while (pos < s.size() && s[pos] != '}' && s[pos] != ',') {
            set<string> next;

            if (s[pos] == '{') {
                pos++;
                next = parseExpression();
                pos++; // skip '}'
            }
            else {
                next.insert(string(1, s[pos]));
                pos++;
            }

            // Concatenate result with next
            set<string> temp;

            for (string a : result) {
                for (string b : next) {
                    temp.insert(a + b);
                }
            }

            result = temp;
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        pos = 0;

        set<string> result = parseExpression();

        return vector<string>(result.begin(), result.end());
    }
};
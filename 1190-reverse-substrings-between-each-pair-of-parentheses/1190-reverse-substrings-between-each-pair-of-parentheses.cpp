class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string cur = "";

        for (char c : s) {
            if (c == '(') {
                // Save the string before '('
                st.push(cur);
                cur = "";
            }
            else if (c == ')') {
                // Reverse the current substring
                reverse(cur.begin(), cur.end());

                // Add it to the previous string
                cur = st.top() + cur;
                st.pop();
            }
            else {
                cur += c;
            }
        }

        return cur;
    }
};
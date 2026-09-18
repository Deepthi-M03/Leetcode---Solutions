class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int> first(26, n);
        vector<int> last(26, -1);

        // Find first and last occurrence of every character
        for (int i = 0; i < n; i++) {
            int character = s[i] - 'a';
            first[character] = min(first[character], i);
            last[character] = i;
        }

        vector<pair<int, int>> selected;
        int previousEnd = -1;

        for (int start = 0; start < n; start++) {
            int character = s[start] - 'a';

            // A valid substring can only start at the first
            // occurrence of its starting character
            if (first[character] != start) {
                continue;
            }

            int end = last[character];
            bool valid = true;

            // Expand the substring when necessary
            for (int i = start; i <= end; i++) {
                int currentCharacter = s[i] - 'a';

                // An occurrence exists before this substring
                if (first[currentCharacter] < start) {
                    valid = false;
                    break;
                }

                end = max(end, last[currentCharacter]);
            }

            if (!valid) {
                continue;
            }

            if (start > previousEnd) {
                // Non-overlapping substring
                selected.push_back({start, end});
            } else {
                // Replace the previous interval with the shorter one
                selected.back() = {start, end};
            }

            previousEnd = end;
        }

        vector<string> answer;

        for (auto [start, end] : selected) {
            answer.push_back(s.substr(start, end - start + 1));
        }

        return answer;
    }
};
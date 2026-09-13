class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1,
                       vector<vector<int>>& img2) {
        int n = img1.size();
        int maximumOverlap = 0;

        // Try every possible vertical and horizontal translation
        for (int rowShift = -(n - 1); rowShift <= n - 1; rowShift++) {
            for (int colShift = -(n - 1); colShift <= n - 1; colShift++) {
                int overlap = 0;

                for (int row = 0; row < n; row++) {
                    for (int col = 0; col < n; col++) {
                        int newRow = row + rowShift;
                        int newCol = col + colShift;

                        if (newRow >= 0 && newRow < n &&
                            newCol >= 0 && newCol < n &&
                            img1[row][col] == 1 &&
                            img2[newRow][newCol] == 1) {
                            overlap++;
                        }
                    }
                }

                maximumOverlap = max(maximumOverlap, overlap);
            }
        }

        return maximumOverlap;
    }
};
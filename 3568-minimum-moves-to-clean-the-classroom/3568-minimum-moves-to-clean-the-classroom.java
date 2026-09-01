import java.util.*;

class Solution {
    public int minMoves(String[] classroom, int energy) {
        int m = classroom.length;
        int n = classroom[0].length();

        int startR = 0, startC = 0;

        int[][] litterId = new int[m][n];
        for (int[] row : litterId) {
            Arrays.fill(row, -1);
        }

        int litterCount = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                char ch = classroom[r].charAt(c);

                if (ch == 'S') {
                    startR = r;
                    startC = c;
                } else if (ch == 'L') {
                    litterId[r][c] = litterCount++;
                }
            }
        }

        int allCollected = (1 << litterCount) - 1;

        if (allCollected == 0) {
            return 0;
        }

        // visited[row][col][mask] = maximum energy we've had
        // when reaching this state.
        int[][][] visited = new int[m][n][1 << litterCount];

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                Arrays.fill(visited[r][c], -1);
            }
        }

        Queue<int[]> queue = new ArrayDeque<>();

        // {row, col, remainingEnergy, mask, moves}
        queue.offer(new int[]{startR, startC, energy, 0, 0});
        visited[startR][startC][0] = energy;

        int[][] dirs = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        while (!queue.isEmpty()) {
            int[] cur = queue.poll();

            int r = cur[0];
            int c = cur[1];
            int remaining = cur[2];
            int mask = cur[3];
            int moves = cur[4];

            if (mask == allCollected) {
                return moves;
            }

            if (remaining == 0) {
                continue;
            }

            for (int[] d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                    continue;
                }

                if (classroom[nr].charAt(nc) == 'X') {
                    continue;
                }

                int newEnergy = remaining - 1;
                int newMask = mask;

                char cell = classroom[nr].charAt(nc);

                // Collect litter
                if (cell == 'L') {
                    int id = litterId[nr][nc];
                    newMask |= (1 << id);
                }

                // Reset energy
                if (cell == 'R') {
                    newEnergy = energy;
                }

                if (newMask == allCollected) {
                    return moves + 1;
                }

                /*
                 * If we have already reached the same:
                 * position + collected-litter state
                 * with equal or more energy,
                 * this new state is useless.
                 */
                if (visited[nr][nc][newMask] >= newEnergy) {
                    continue;
                }

                visited[nr][nc][newMask] = newEnergy;

                queue.offer(new int[]{
                    nr,
                    nc,
                    newEnergy,
                    newMask,
                    moves + 1
                });
            }
        }

        return -1;
    }
}
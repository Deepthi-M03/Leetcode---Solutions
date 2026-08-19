import java.util.*;

class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        Map<Integer, Integer> rows = new HashMap<>();

        // Store reserved seats using bitmask
        for (int[] seat : reservedSeats) {
            int row = seat[0];
            int seatNumber = seat[1];

            // Seats 1 and 10 do not affect any four-seat block
            if (seatNumber >= 2 && seatNumber <= 9) {
                int mask = rows.getOrDefault(row, 0);
                mask |= (1 << seatNumber);
                rows.put(row, mask);
            }
        }

        // Every unaffected row can accommodate two families
        int families = (n - rows.size()) * 2;

        for (int mask : rows.values()) {
            boolean leftFree =
                (mask & ((1 << 2) | (1 << 3) | (1 << 4) | (1 << 5))) == 0;

            boolean middleFree =
                (mask & ((1 << 4) | (1 << 5) | (1 << 6) | (1 << 7))) == 0;

            boolean rightFree =
                (mask & ((1 << 6) | (1 << 7) | (1 << 8) | (1 << 9))) == 0;

            if (leftFree && rightFree) {
                families += 2;
            } else if (leftFree || middleFree || rightFree) {
                families += 1;
            }
        }

        return families;
    }
}
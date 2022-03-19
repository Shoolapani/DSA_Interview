// import java.io.*;
import java.util.*;

class test {
    static int uniquePaths(int m, int n) {
        int count[][] = new int[m][n];

        for (int i = 0; i < m; i++) {
            count[i][0] = 1;
        }

        for (int j = 0; j < n; j++) {
            count[0][j] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                count[i][j] = count[i - 1][j] + count[i][j - 1];
            }
        }
        return count[m - 1][n - 1];
    }

    static int[] twoSum(int[] nums, int target) {
        int ans[] = new int[2];
        Map<Integer, Integer> uMap = new HashMap<Integer, Integer>();

        for (int i = 0; i < nums.length; i++) {
            if (uMap.containsKey(target - nums[i])) {
                ans[0] = i;
                ans[1] = uMap.get(target - nums[i]);
                return ans;
            }
            uMap.put(nums[i], i);
        }

        return ans;
    }

    static int longestConsecutive(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }

        int size = 1, maxSize = 1;
        Set<Integer> hashSet = new HashSet<Integer>();

        for (int i : nums) {
            hashSet.add(i);
        }

        for (int i : nums) {
            if (!hashSet.contains(i - 1)) {
                while (hashSet.contains(i + 1)) {
                    ++size;
                    ++i;
                }
                maxSize = Math.max(maxSize, size);
                size = 1;
            }
        }

        return maxSize;
    }

    static int maxLen(int arr[], int n) {
        int sum = 0, maxLen = 0;
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();

        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];
            if (sum == 0) {
                maxLen = i + 1;
            } else if (!map.containsKey(sum)) {
                map.put(sum, i);
            } else {
                maxLen = Math.max(maxLen, i - map.get(sum));
            }
        }
        return maxLen;
    }

    static int solve(int[] A, int B) {
        int c = 0, y = 0, xr = 0;
        Map<Integer, Integer> visited = new HashMap<>();

        for (int i : A) {
            xr ^= i;
            if (xr == B) {
                ++c;
            }
            y = xr ^ B;

            if (visited.containsKey(y)) {
                c += visited.get(y);
            }
            if (visited.get(xr) != null) {
                visited.put(xr, visited.get(xr) + 1);
            } else {
                visited.put(xr, 1);
            }
        }
        return c;
    }

    public static int lengthOfLongestSubstring(String s) {
        int len = 0, r = 0, l = 0;
        Map<Character, Integer> map = new HashMap<>();

        while (r < s.length()) {
            if (map.containsKey(s.charAt(r))) {
                l = Math.max(l, map.get(s.charAt(r)) + 1);
            }
            map.put(s.charAt(r), r);
            len = Math.max(len, r - l + 1);
        }
        ++r;
        return len;
    }

    public static void main(String[] args) {
        int arr[] = { 7, 1, -1, 1, -1, 4 };
        // System.out.println(uniquePaths(3, 3));
        // System.out.println(longestConsecutive(arr));
        System.out.println(maxLen(arr, arr.length));
    }
}

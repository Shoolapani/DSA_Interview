import java.io.*;
import java.util.*;
import java.util.LinkedList;

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

    static int countHillValley(int[] nums) {
        int count = 0;

        for (int i = 1; i < nums.length - 1; i++) {
            if ((nums[i] != nums[i - 1]) && (nums[i] != nums[i + 1])) {
                if ((nums[i] < nums[i - 1]) && (nums[i] < nums[i + 1])) {
                    ++count;
                } else if ((nums[i] > nums[i - 1]) && (nums[i] > nums[i + 1])) {
                    ++count;
                }
            } else {
                int j = i - 1, k = i + 1;
                while ((nums[j] == nums[j + 1])) {
                    --j;
                    if (j < 0) {
                        break;
                    }
                }
                while ((nums[k] == nums[k - 1]) && (k < nums.length)) {
                    ++k;
                    if (k >= nums.length) {
                        break;
                    }
                }

                if ((j < 0)) {
                    continue;
                }
                if (k >= nums.length) {
                    continue;
                }

                if ((nums[i] < nums[j]) && (nums[i] < nums[k])) {
                    ++count;
                } else if ((nums[i] > nums[j]) && (nums[i] > nums[k])) {
                    ++count;
                }
                i = k - 1;
            }
        }

        return count;
    }

    public int removeDuplicates(int[] nums) {
        int num = nums[0], ind = 1;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != num) {
                num = nums[i];
                // swap(nums[i], nums[ind++]);
                nums[i] = nums[i] ^ nums[ind];
                nums[ind] = nums[i] ^ nums[ind];
                nums[i] = nums[i] ^ nums[ind];
                ind++;
            }
        }

        return ind;
    }

    public int findMaxConsecutiveOnes(int[] nums) {
        int maxCount = 0, count = 0;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 1) {
                ++count;
            } else {
                count = 1;
            }
            maxCount = Math.max(maxCount, count);
        }
        return maxCount;
    }

    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new LinkedList<>();
        Arrays.sort(nums);

        for (int i = 0; i < nums.length - 2; i++) {
            int lo = i + 1, high = (nums.length - 1), a = 0 - nums[i];

            if ((i == 0) || (i > 0 && (nums[i] != nums[i - 1]))) {
                while (lo < high) {
                    if (nums[lo] + nums[high] == a) {
                        ans.add(Arrays.asList(nums[i], nums[lo], nums[high]));

                        while (lo < high && (nums[lo] == nums[lo + 1]))
                            ++lo;
                        while (lo < high && (nums[high] == nums[high - 1]))
                            --high;

                        ++lo;
                        --high;

                    } else if (nums[lo] + nums[high] < a) {
                        ++lo;
                    } else {
                        --high;
                    }
                }
            }
        }
        return ans;
    }

    public List<List<Integer>> threeSum4(int[] nums) {
        List<List<Integer>> ans = new LinkedList<>();

        for (int i = 0; i < nums.length - 2; i++) {
            for (int j = i + 1; j < nums.length - 1; j++) {
                List<Integer> d = new LinkedList<>();

                for (int j2 = j + 1; j2 < nums.length; j2++) {
                    if (nums[i] + nums[j] + nums[j2] == 0) {
                        d.add(nums[i]);
                        d.add(nums[j]);
                        d.add(nums[j2]);

                        // ans.add(Arrays.asList(nums[i], nums[j], nums[j2]));
                    }

                    if (d.isEmpty() == false) {
                        ans.add(d);
                    }
                }
            }
        }
        return ans;
    }

    static int findPlatform(int arr[], int dep[], int n) {
        int arrInd = 1, depInd = 0, platCount = 1, maxCount = 1;
        Arrays.sort(arr);
        Arrays.sort(dep);

        while ((arrInd < n) && (depInd < n)) {
            if (arr[arrInd] > dep[depInd]) {
                ++depInd;
                --platCount;
            } else if (arr[arrInd] <= dep[depInd]) {
                ++platCount;
                ++arrInd;
            }
            maxCount = Math.max(maxCount, platCount);
        }

        return maxCount;
    }

    static boolean isPalindrome(String s, int start, int end) {
        int i = start, j = end;

        while (i <= j) {
            if (s.charAt(i++) != s.charAt(j--)) {
                return false;
            }
        }
        return true;
    }

    static void func(String s, int ind, List<List<String>> ans, List<String> ds) {
        if (ind == s.length()) {
            ans.add(new ArrayList<>(ds));
            return;
        }

        for (int i = ind; i < s.length(); i++) {
            if (isPalindrome(s, ind, i)) {
                ds.add(s.substring(ind, i + 1));
                func(s, i + 1, ans, ds);
                ds.remove(ds.size() - 1);
            }
        }
        return;
    }

    static List<List<String>> partition(String s) {
        List<List<String>> ans = new ArrayList<>();
        List<String> ds = new ArrayList<>();
        func(s, 0, ans, ds);
        return ans;
    }

    public static void main(String[] args) {
        int arr[] = { 57, 57, 57, 57, 57, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 85, 85,
                85, 86, 86, 86 };
        // System.out.println(uniquePaths(3, 3));
        // System.out.println(longestConsecutive(arr));
        System.out.println(countHillValley(arr));
    }
}

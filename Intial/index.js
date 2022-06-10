var findMedianSortedArrays = function (nums1, nums2) {
  if (nums2.length < nums1.length) {
    return findMedianSortedArrays(nums2, nums1);
  }
  let n1 = nums1.length;
  let n2 = nums2.length;
  let low = 0,
    high = n1;
  let l1 = Number.MIN_SAFE_INTEGER,
    l2 = Number.MIN_SAFE_INTEGER,
    r1 = Number.MAX_SAFE_INTEGER,
    r2 = Number.MAX_SAFE_INTEGER;

  while (low <= high) {
    let cut1 = (high + low) >> 1;
    let cut2 = (n1 + n2 + 1) / 2 - cut1;

    l1 = cut1 === 0 ? Number.MIN_SAFE_INTEGER : nums1[cut1 - 1];
    l2 = cut2 === 0 ? Number.MIN_SAFE_INTEGER : nums2[cut2 - 1];

    r1 = cut1 === n1 ? Number.MAX_SAFE_INTEGER : nums1[cut1];
    r2 = cut2 === n2 ? Number.MAX_SAFE_INTEGER : nums2[cut2];

    if (l1 <= r2 && l2 <= r1) {
      if ((n1 + n2) % 2 === 0) {
        return (Math.max(l1, l2) + Math.min(r1, r2)) / 2.0;
      } else {
        return Math.max(l1, l2);
      }
    } else if (l1 > r2) {
      high = cut1 - 1;
    } else {
      low = cut1 + 1;
    }
  }

  return 0.0;
};

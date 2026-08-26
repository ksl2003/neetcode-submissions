class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int reqMid = (n1 + n2) / 2;
        int n = n1 + n2;
        double ans = 0;
        if (n1 <= n2) {
            int low = 0, high = n1;
            while (low <= high) {
                int mid1 = (low + high) / 2;
                int mid2 = reqMid - mid1;
                if (mid2 < 0) {
                    high = mid1 - 1;
                    continue;
                }
                if (mid2 > n2) {
                    low = mid1 + 1;
                    continue;
                }

                int l1 = INT_MIN, l2 = INT_MIN;
                int r1 = INT_MAX, r2 = INT_MAX;
                if (mid1 > 0) {
                    l1 = nums1[mid1 - 1];
                }
                if (mid2 > 0) {
                    l2 = nums2[mid2 - 1];
                }
                if (mid1 < n1) {
                    r1 = nums1[mid1];
                }
                if (mid2 < n2) {
                    r2 = nums2[mid2];
                }

                if (l1 <= r2 && l2 <= r1) {
                    if (n % 2 == 0) {
                        ans = (max(l1, l2) + min(r1, r2)) / (2.0);
                    } else {
                        ans = min(r1, r2);
                    }
                    break;
                } else if (l1 > r2) {
                    high = mid1 - 1;
                } else {
                    low = mid1 + 1;
                }
            }
        } else {
            int low = 0, high = n2;
            while (low <= high) {
                int mid2 = (low + high) / 2;
                int mid1 = reqMid - mid2;
                if (mid1 < 0) {
                    high = mid2 - 1;
                    continue;
                }
                if (mid1 > n1) {
                    low = mid2 + 1;
                    continue;
                }

                int l1 = INT_MIN, l2 = INT_MIN;
                int r1 = INT_MAX, r2 = INT_MAX;
                if (mid1 > 0) {
                    l1 = nums1[mid1 - 1];
                }
                if (mid2 > 0) {
                    l2 = nums2[mid2 - 1];
                }
                if (mid1 < n1) {
                    r1 = nums1[mid1];
                }
                if (mid2 < n2) {
                    r2 = nums2[mid2];
                }

                if (l1 <= r2 && l2 <= r1) {
                    if (n % 2 == 0) {
                        ans = (max(l1, l2) + min(r1, r2)) / (2.0);
                    } else {
                        ans = min(r1, r2);
                    }
                    break;
                } else if (l2 > r1) {
                    high = mid2 - 1;
                } else {
                    low = mid2 + 1;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    /**
     * @brief Merges nums2 into nums1 as one sorted array.
     * Strategy: Two-pointers from right to left to achieve O(1) space.
     */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;      // Pointer for nums1
        int j = n - 1;      // Pointer for nums2
        int k = m + n - 1;  // Placement pointer

        // Iteratively place the largest available element at the end
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // Only need to fill the remaining elements from nums2
        // because nums1 elements are already in place
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};
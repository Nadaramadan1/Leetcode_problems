# Intuition
The problem asks to merge two sorted arrays in-place within nums1. Since nums1 has extra space at the end, the most efficient way is to work backwards. By comparing the largest elements of both arrays and placing them at the end of nums1, we avoid the overhead of shifting elements, which would occur if we started from the beginning.

# Approach
1)Three-Pointer Technique: 
Initialize three pointers:
i: Points to the last actual element in nums1 ($m - 1$).
j: Points to the last element in nums2 ($n - 1$).
k: Points to the very last position in nums1 ($m + n - 1$).

2)Backward Comparison: Compare nums1[i] and nums2[j]. 
Place the larger value at nums1[k] and decrement the corresponding pointers.

3)Handle Remaining Elements:If nums2 still has elements left after nums1 is exhausted, copy them into the remaining positions of nums1.
If nums1 elements are exhausted first, they are already in their correct sorted positions, so no further action is needed for i.

# Complexity
- Time complexity:
- **O(m + n)**
We perform a single pass through both arrays, visiting each element at most once.
- Space complexity:
- **O(1)**
We are modifying nums1 in-place without using any additional data structures or extra memory proportional to the input size.

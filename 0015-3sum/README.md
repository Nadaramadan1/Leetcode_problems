# Intuition
Finding triplets that sum to zero can be computationally expensive $(O(n^3))$ if we use a brute-force approach. To optimize this, we can sort the array and transform the problem into a series of Two-Sum problems. By fixing one element and using two pointers (left and right), we can scan the rest of the array in linear time, resulting in a quadratic overall complexity.

# Approach
Sorting: We start by sorting the array. This is crucial for two reasons: it allows us to use the two-pointer technique and makes it easier to skip duplicate values.

Fixed Pointer (i): We iterate through the array. If the current element nums[i] is greater than zero, we break the loop because no three positive numbers can sum to zero.

Skipping Duplicates: To ensure unique triplets, we skip any element that is identical to the one before it.

Two-Pointer Scan:

left pointer starts at i + 1.

right pointer starts at the end of the array.

If sum == 0, we've found a valid triplet. We then move both pointers, skipping any identical adjacent values to avoid duplicate triplets in the output.

If sum < 0, we move the left pointer forward to increase the sum.

If sum > 0, we move the right pointer backward to decrease the sum.

# Complexity
- Time complexity:O(n^2)
Sorting takes O(n \log n)
The nested loops (one for loop and one while loop for pointers) result in O(n^2).Since O(n^2) dominates O(n \log n), the final complexity is quadratic.

- Space complexity:O(1) or O(\log n)
- Excluding the space required for the output list, we only use a constant amount of extra space for pointers. Some space is used internally by the sorting algorithm.


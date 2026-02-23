/**
 * @file Contains Duplicate.cpp
 * @brief Checks if any value appears at least twice in an array.
 * * Strategy: Using unordered_set for O(1) average time complexity lookups.
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Hash Set to store elements we have already encountered
        unordered_set<int> seen;

        for (int num : nums) {
            // If the element is already in the set, we found a duplicate
            if (seen.find(num) != seen.end()) {
                return true;
            }
            // Otherwise, insert it into the set
            seen.insert(num);
        }

        // No duplicates found after scanning the entire array
        return false;
    }
};
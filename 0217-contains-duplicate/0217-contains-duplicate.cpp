/**
 * @file ContainsDuplicate.cpp
 * @author Nada
 * @brief Optimized solution using STL container properties for duplicate detection.
 * * Performance:
 * - Time: O(n) average
 * - Space: O(n)
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Constructing a set from the vector range automatically handles duplicates.
        // A smaller size indicates at least one element was a duplicate.
        return unordered_set<int>(nums.begin(), nums.end()).size() < nums.size();
    }
};
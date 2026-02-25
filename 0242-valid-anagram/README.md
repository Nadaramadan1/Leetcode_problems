# Intuition
The core idea of an anagram is character frequency parity. Instead of the overhead of **Sorting** ($O(n \log n)$), we can leverage the fixed constraints of the problem (26 lowercase English letters) to create a high-performance "Balance Sheet" for characters. My first thought was to use a simple frequency array to track the net difference between the two strings in a single pass.

# Approach
1. **Early Exit Strategy:** Check if both strings have the same length. If not, they cannot be anagrams (an $O(1)$ check).
2. **Frequency Balance Array:** Initialize a fixed-size integer array of **26** elements (representing 'a' through 'z') to zero. 
3. **The "Net-Zero" Scan:** Iterate through both strings simultaneously. For each character in string `s`, increment its corresponding index in the array (`s[i] - 'a'`). For each character in string `t`, decrement its corresponding index (`t[i] - 'a'`).
    * *Why?* This simulates adding a character to a "pool" from `s` and removing it if it exists in `t`.
4. **Final Validation:** After the loop, if every value in the array is exactly **0**, the strings are anagrams. Any non-zero value indicates a mismatch in character counts.

# Complexity
- **Time complexity:**
$$O(n)$$
We traverse the strings exactly once (where $n$ is the length of the string). The final check over the 26-slot array is $O(1)$ because it doesn't scale with input size.

- **Space complexity:**
$$O(1)$$
We use a fixed-size array of 26 integers. Regardless of whether the input strings have 10 or 50,000 characters, our memory usage remains constant.

# Code
```cpp
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @brief Determines if string t is an anagram of string s.
     * Optimized using a fixed-size frequency array for O(n) time and O(1) space.
     */
    bool isAnagram(string s, string t) {
        // Optimization: Strings of different lengths cannot be anagrams
        if (s.length() != t.length()) return false;

        // Fixed-size frequency array for English lowercase letters (a-z)
        // Stack-allocated for faster access compared to heap-based maps
        int count[26] = {0};

        // Single pass to update character frequency balance
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++; 
            count[t[i] - 'a']--; 
        }

        // Final verification: Every character count must balance to zero
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return false;
        }

        return true;
    }
};

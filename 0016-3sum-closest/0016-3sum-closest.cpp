#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


auto speedup = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; ++i) {
      
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;

         
            int minSum = nums[i] + nums[left] + nums[left + 1];
            if (minSum > target) {
                if (abs(minSum - target) < abs(closestSum - target)) closestSum = minSum;
                continue; 
            }
            
           
            int maxSum = nums[i] + nums[right - 1] + nums[right];
            if (maxSum < target) {
                if (abs(maxSum - target) < abs(closestSum - target)) closestSum = maxSum;
                continue;
            }

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                
                if (currentSum == target) return target;

                if (abs(currentSum - target) < abs(closestSum - target)) {
                    closestSum = currentSum;
                }

                if (currentSum < target) {
                    left++;
                
                    while (left < right && nums[left] == nums[left - 1]) left++;
                } else {
                    right--;
                   
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
            }
        }
        return closestSum;
    }
};
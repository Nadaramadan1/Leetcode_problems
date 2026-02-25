#include <algorithm>
#include <vector>

using namespace std;

static const int speedup = []() {
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

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;
            int current_val = nums[i]; 

          
            int min_sum = current_val + nums[left] + nums[left + 1];
            if (min_sum > target) {
                if (min_sum - target < abs(closestSum - target))
                    closestSum = min_sum;
               
                continue;
            }

           
            int max_sum = current_val + nums[right - 1] + nums[right];
            if (max_sum < target) {
                if (target - max_sum < abs(closestSum - target))
                    closestSum = max_sum;
                
                continue;
            }

            while (left < right) {
                int sum = current_val + nums[left] + nums[right];

                if (sum == target)
                    return target;

                if (abs(sum - target) < abs(closestSum - target)) {
                    closestSum = sum;
                }

                if (sum < target) {
                    left++;
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                } else {
                    right--;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
            }
        }
        return closestSum;
    }
};
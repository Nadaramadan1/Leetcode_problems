class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        // سطر تسريع الـ I/O - أساسي للـ 100%
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> result;
        // التريك: بنحجز المساحة فوراً لمنع أي إعادة تخصيص (Reallocation)
        result.reserve(2 * n);
        
        for (int i = 0; i < n; ++i) {
            // استخدام push_back بعد الـ reserve بيكون سريع جداً
            result.push_back(nums[i]);
            result.push_back(nums[i + n]);
        }
        
        return result;
    }
};
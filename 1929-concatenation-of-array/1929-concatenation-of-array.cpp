class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        // سطر السحر - لازم يكون جوا الدالة لو لسه السكور منخفض
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        vector<int> ans(2 * n);
        
        // استخدام memcpy أو pointer manipulation أسرع بكتير
        // بس خلينا في الـ Loop المنظمة لأنها "أشيك" في المقابلات
        for (int i = 0; i < n; ++i) {
            ans[i] = ans[i + n] = nums[i];
        }
        
        return ans;
    }
};
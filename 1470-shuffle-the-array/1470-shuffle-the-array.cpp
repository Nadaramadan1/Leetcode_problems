class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        // بنعمل مصفوفة جديدة عشان نحط فيها الترتيب الجديد
        vector<int> result(2 * n);
        
        // j ده مؤشر للمكان اللي بنملى فيه في المصفوفة الجديدة
        int j = 0;
        
        for (int i = 0; i < n; i++) {
            // حطي رقم من النص الأول
            result[j] = nums[i];
            // حطي الرقم اللي قصاده من النص التاني
            result[j + 1] = nums[i + n];
            
            // زودي j بـ 2 عشان المرة الجاية نحط في الخانتين اللي بعدهم
            j += 2;
        }
        
        return result;
    }
};
#include <vector>

using namespace std;

// السر الحقيقي لـ 0ms في LeetCode
static const int speedup = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        // مصفوفة ثابتة سريعة جداً
        bool isOn[101] = {false};
        
        for (int b : bulbs) {
            isOn[b] = !isOn[b]; 
        }
        
        vector<int> result;
        // حركة ذكية: نحجز مساحة مسبقاً لتقليل الـ Overhead
        result.reserve(100); 
        
        for (int i = 1; i <= 100; ++i) {
            if (isOn[i]) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};
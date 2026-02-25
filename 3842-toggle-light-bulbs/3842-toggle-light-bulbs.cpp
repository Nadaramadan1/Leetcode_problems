#include <vector>

using namespace std;

// تسريع الـ I/O لضمان 100% Beats
static const int speedup = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
     
        bool isOn[101] = {false};
        
       
        for (int b : bulbs) {
            isOn[b] = !isOn[b]; 
        }
        
       
        vector<int> result;
        for (int i = 1; i <= 100; ++i) {
            if (isOn[i]) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};
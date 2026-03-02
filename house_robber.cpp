#include <iostream>
#include <vector>
#include <algorithm> // C++ 标准库，为了使用 max 函数

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // 1. 极其凶险的边界防御：如果没有房子，或者只有 1 间房子
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            int current_money = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = current_money;
        }

        return prev1;
    }
};

// 导师测试车身
int main() {
    Solution sol;
    
    vector<int> street1 = {1, 2, 3, 1};
    cout << "街道 1 最大收益: " << sol.rob(street1) << " (期望: 4)" << endl;
    
    vector<int> street2 = {2, 7, 9, 3, 1};
    cout << "街道 2 最大收益: " << sol.rob(street2) << " (期望: 12)" << endl;
    
    vector<int> street3 = {2}; // 极限情况测试
    cout << "街道 3 最大收益: " << sol.rob(street3) << " (期望: 2)" << endl;
    
    return 0;
}
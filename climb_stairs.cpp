#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // 1. 极小边界处理：如果楼梯只有 1 阶或 2 阶，不用算，直接返回 n
        if (n == 1 || n == 2) {
            return n;
        }
        
        // 2. 创建 DP 备忘录数组
        // 为了让下标 i 刚好对应第 i 阶楼梯，我们把数组大小开到 n + 1
        // 注意：这里用到了 C++ 的 vector 容器
        vector<int> dp(n + 1);
        
        // 3. 填入初始边界 (Base Case)
        // dp[1] = ?
        // dp[2] = ?
        dp[1] = climbStairs(1);
        dp[2] = climbStairs(2);
        // 4. 开始从第 3 阶往上爬（写一个 for 循环）
        // 在循环里使用状态转移方程填满 dp 数组
        for (int i = 3; i < n + 1; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        // 5. 爬到顶了！返回数组最后一个元素的值
        return dp.back();
    }
};

// 导师测试车身
int main() {
    Solution sol;
    cout << "爬 2 阶的方法数: " << sol.climbStairs(2) << " (期望: 2)" << endl;
    cout << "爬 3 阶的方法数: " << sol.climbStairs(3) << " (期望: 3)" << endl;
    cout << "爬 5 阶的方法数: " << sol.climbStairs(5) << " (期望: 8)" << endl;
    cout << "爬 45 阶的方法数: " << sol.climbStairs(45) << " (期望: 1836311903)" << endl;
    return 0;
}
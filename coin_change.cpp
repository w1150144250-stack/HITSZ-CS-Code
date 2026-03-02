#include <iostream>
#include <vector>
#include <algorithm> // 为了使用 min 函数

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 1. 创建 DP 备忘录，大小为 amount + 1
        // 把所有的坑位都填上我们定义的“无穷大” (amount + 1)
        int INF = amount + 1;
        vector<int> dp(amount + 1, INF);
        
        // 2. Base Case: 凑齐 0 元需要 0 个硬币
        dp[0] = 0;
        
        // 3. 开始从小到大算，金额 i 从 1 一直算到 amount
        for (int i = 1; i <= amount; i++) {
            
            // 4. 对于当前的金额 i，我们去尝试手里的每一种硬币
            for (int j = 0; j < coins.size(); j++) {
                int coin = coins[j];
                
                // 🟥 你的主战场在这里！
                // 严师警告：只有当你想要凑的金额 i 大于等于硬币面值 coin 时，你才能用这枚硬币！
                if (i >= coin) {
                    
                    // 【请在这里写下你的状态转移方程】
                    // 提示：你需要用 min 函数，比较“原本的 dp[i]”和“用了一枚当前硬币后的 dp[i - coin] + 1”，
                    // 选更小的那个存进 dp[i] 里。
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                    
                }
            }
        }
        
        // 5. 验收结果
        // 如果 dp[amount] 还是那个 INF，说明没有任何硬币组合能凑出来
        if (dp[amount] == INF) {
            return -1;
        } else {
            return dp[amount];
        }
    }
};

// 导师测试车身
int main() {
    Solution sol;
    
    vector<int> coins1 = {1, 2, 5};
    cout << "凑齐 11 元最少硬币数: " << sol.coinChange(coins1, 11) << " (期望: 3)" << endl;
    
    vector<int> coins2 = {2};
    cout << "凑齐 3 元最少硬币数: " << sol.coinChange(coins2, 3) << " (期望: -1)" << endl;
    
    vector<int> coins3 = {1};
    cout << "凑齐 0 元最少硬币数: " << sol.coinChange(coins3, 0) << " (期望: 0)" << endl;
    
    return 0;
}
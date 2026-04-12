#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result; // 存放所有结果的大箩筐
    vector<int> path;           // 探险家走过的当前路径（毛线）

    // 核心深搜函数
    // nums: 原始数组
    // used: 记录哪个数字已经被用过了（相当于走过的死胡同）
    void dfs(const vector<int>& nums, vector<bool>& used) {
        // 1. 触发终点条件：当发现手中拿的数字个数等于原数组长度时，说明凑齐了一个排列
        if (path.size() == nums.size()) {
            result.push_back(path); // 把当前路径装进箩筐
            return; // 撞到南墙，准备回头！
        }

        // 2. 站在岔路口：尝试所有的数字
        for (int i = 0; i < nums.size(); i++) {
            // 如果这个数字在当前路径里已经用过了，跳过
            if (used[i]) continue;

            // 🟥 核心三步曲之 1：做选择（踏入岔路）
            path.push_back(nums[i]);
            used[i] = true;

            // 🟥 核心三步曲之 2：递归深搜（顺着这条路死命往里走）
            dfs(nums, used);

            // 🟥 核心三步曲之 3：撤销选择 / 恢复现场（退回岔路口！）
            // 这是最难懂的一步。从上面的 dfs 退出来，说明上一条路已经探到底了。
            // 此时必须把刚加进去的数字拿出来，状态重置，才能去走下一个 i。
            path.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        dfs(nums, used);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = sol.permute(nums);

    cout << "数组 [1, 2, 3] 的全排列有：" << endl;
    for (const auto& p : ans) {
        cout << "[";
        for (int i = 0; i < p.size(); i++) {
            cout << p[i] << (i == p.size() - 1 ? "" : ", ");
        }
        cout << "]" << endl;
    }
    
    return 0;
}
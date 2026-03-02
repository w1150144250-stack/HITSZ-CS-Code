#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 注意返回值类型：vector<int> 代表一个大小可变的整型数组
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map; // 你的魔法笔记本
        
        // 遍历整个数组
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; // 算出你需要配对的目标数字
            if (map.count(complement) > 0) {
                return {map[complement], i};
            }
            map[nums[i]] = i;

        }
        
        return {}; // 兜底：如果没找到，返回空数组
    }
};

// 导师测试车身
int main() {
    Solution sol;
    vector<int> nums1 = {2, 7, 11, 15};
    vector<int> ans1 = sol.twoSum(nums1, 9);
    if(ans1.size() == 2) cout << "测试 1: [" << ans1[0] << ", " << ans1[1] << "]" << endl;

    vector<int> nums2 = {3, 2, 4};
    vector<int> ans2 = sol.twoSum(nums2, 6);
    if(ans2.size() == 2) cout << "测试 2: [" << ans2[0] << ", " << ans2[1] << "]" << endl;
    
    return 0;
}
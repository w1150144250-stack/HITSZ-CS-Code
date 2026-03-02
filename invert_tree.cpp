#include <iostream>

using namespace std;

// 二叉树节点的标准定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // 1. 递归的终止条件：如果节点为空，直接返回空指针
        if (root == nullptr) return root;
        
        // 2. 核心操作：交换当前节点 root 的左右子节点
        // 提示：你可以用一个 TreeNode* temp 来辅助交换，就像你交换两个数字一样
        swap(root->left, root->right);
        
        // 3. 施展递归魔法：命令左子树去翻转自己，命令右子树去翻转自己
        // (调用自身函数即可)
        invertTree(root->left);
        invertTree(root->right);
        
        // 4. 全部翻转完毕，返回当前这棵树的根节点
        return root;
    }
};
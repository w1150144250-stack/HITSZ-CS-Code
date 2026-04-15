#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<vector<string>> result; // 存放所有成功的棋盘

    // 🕵️ 查杀函数：检查在 (row, col) 放皇后是否安全
    // 严师提示：因为我们是一行一行往下搜的，下面还没放皇后，绝对安全！
    // 只需要检查【正上方】、【左上方对角线】、【右上方对角线】。
    bool isValid(const vector<string>& board, int row, int col) {
        int n = board.size();
        // 检查正上方
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }
        // 检查左上方对角线
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        // 检查右上方对角线
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        return true; // 绝对安全！
    }

    // 🟥 你的主战场：核心回溯逻辑
    // row: 探险家当前走到了第几行
    void backtrack(vector<string>& board, int row) {
        int n = board.size();
        
        // 1. 触发终点条件：如果走到了最后一行之后 (row == n)，说明 N 个皇后都安全放下了！
        if (row == n) {
            // 【TODO 1: 把当前完美棋盘 board 塞进 result 里，然后 return 撤退】
            result.push_back(board);
            return;
        }

        // 2. 站在岔路口：尝试在当前行 (row) 的每一列 (col) 放皇后
        for (int col = 0; col < n; col++) {
            // 必须先通过查杀！如果这一步会死，直接跳过 (continue)
            if (!isValid(board, row, col)) {
                continue;
            }

            // 🟥 【TODO 2: 核心三步曲 1：做选择（在这个位置 board[row][col] 放上皇后 'Q'）】
            board[row][col] = 'Q';

            // 🟥 【TODO 3: 核心三步曲 2：递归深搜（带着当前的棋盘，前往下一行 row + 1 探索）】
            backtrack(board, row + 1);

            // 🟥 【TODO 4: 核心三步曲 3：撤销选择 / 恢复现场（把刚才放的 'Q' 变回 '.'，退回岔路口去试下一列）】
            board[row][col] = '.';
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        // 初始化一个 N*N 的空棋盘，全是 '.'
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0); // 从第 0 行开始探索
        return result;
    }
};

// 导师测试车身
int main() {
    Solution sol;
    int n = 4; // 先用 4 皇后测试。如果是 8 皇后，标准答案是 92 种！
    vector<vector<string>> ans = sol.solveNQueens(n);

    cout << n << " 皇后问题共有 " << ans.size() << " 种解法：" << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << "解法 " << i + 1 << ":" << endl;
        for (const string& r : ans[i]) {
            cout << r << endl;
        }
        cout << "--------" << endl;
    }
    return 0;
}
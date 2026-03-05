#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 定义坐标点
struct Point {
    int x, y, step;
};

int solve_maze() {
    int n, m;
    // 假设输入地图大小
    if (!(cin >> n >> m)) return -1;

    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // 方向数组：上下左右
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    queue<Point> q;
    q.push({0, 0, 0}); // 起点
    visited[0][0] = true;

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        // 到达终点
        if (curr.x == n - 1 && curr.y == m - 1) {
            return curr.step;
        }

        // 尝试四个方向
        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            // 严谨性检查：边界检查、是否是墙、是否访问过
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && 
                grid[nx][ny] == 0 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny, curr.step + 1});
            }
        }
    }

    return -1; // 无法到达
}

int main() {
    cout << "请输入迷宫大小(n m)及矩阵(0路1墙):" << endl;
    int result = solve_maze();
    if (result != -1) {
        cout << "最短路径长度为: " << result << endl;
    } else {
        cout << "无路可逃！" << endl;
    }
    return 0;
}
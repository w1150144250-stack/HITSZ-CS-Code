#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Point {
    int r;
    int c;
    int dist;
};

void solve() {
    int n, m, k;
    if (!(cin >> n >> m >> k)) return;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int H = n + 2 * k;
    int W = m + 2 * k;

    vector<vector<bool>> vis(H, vector<bool> (W, false));
    queue<Point> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#') {
                q.push({i + k, j + k, 0});
                vis[i + k][j + k] = true;
            }
        }
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        Point p = q.front();
        q.pop();

        if (p.dist == k) continue;

        for (int i = 0; i < 4; i++) {
            int nr = p.r + dr[i];
            int nc = p.c + dc[i];

            if (nr >= 0 && nr < H && nc >= 0 && nc < W) {
                if (!vis[nr][nc]) {
                    vis[nr][nc] = true;
                    q.push({nr, nc, p.dist + 1});
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (vis[i][j]) {
                int orig_r = i - k;
                int orig_c = j - k;
                bool is_land = true;

                if (orig_r >= 0 && orig_r < n && orig_c >= 0 && orig_c < m) {
                    if (grid[orig_r][orig_c] == '#') {
                        is_land = false;
                    }
                }

                if (is_land) {
                    ans++;
                }
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
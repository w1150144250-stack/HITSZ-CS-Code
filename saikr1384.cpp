#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    if (!getline(cin, line)) return 0;

    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ':' || line[i] == '.') {
            line[i] = ' ';
        }
    }

    stringstream ss(line);

    int h1, h2, m1, m2, s1, s2, hs1, hs2;
    if (!(ss >> h1 >> m1 >> s1 >> hs1 >> h2 >> m2 >> s2 >> hs2)) return 0;

    long long ans = (h2 - h1) * 360000 + (m2 - m1) * 6000  + (s2 - s1) * 100 + (hs2 - hs1);

    cout << ans << '\n';
    return 0;
}
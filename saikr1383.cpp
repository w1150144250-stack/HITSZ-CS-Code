#include <iostream>
#include <map>

using namespace std;

void solve() {
    int n;
    cin >> n;

    map<int, long long> counts;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        counts[val]++;
    }

    long long ans = 0;
    
    for (auto const& [val, count] : counts) {
        if (count >= 2) {
            ans += (count * (count - 1)) / 2 ;
        }

    }

    if (counts.count(1) && counts.count(2)) {
        ans += counts[1] * counts[2];
    }

    cout << ans << '\n';

}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }

    return 0;
}